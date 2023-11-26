/*
 * @Author: PapillonAz 1065940593@qq.com
 * @Date: 2023-11-22 15:39:16
 * @LastEditors: PapillonAz 1065940593@qq.com
 * @LastEditTime: 2023-11-26 16:07:22
 * @FilePath: /Simple_geometric_expert_system/code/source/Engine.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "../include/Engine.h"
#include <regex>
#include <string>
#include <vector>

std::regex re_a_rule("(\\{.*?\\})");
std::regex re_if_part("^\\{IF:\\s+(\\[.*?\\])");
std::regex re_then_part("THEN:\\s+(\'.*?\')");
std::regex re_description_part("DESCRIPTION:\\s+(\'.*?\')");

Engine::Engine(std::vector<Rule> rule_library, std::map<std::string, ContourFact> facts_library) : rule_library(rule_library), facts_library(facts_library) {

}

Engine::~Engine() {

}

void Engine::pushConditionStack(std::string condition) {
    condition_stack.push(condition);
}

void Engine::clearConditionStack() {
    while (!condition_stack.empty()) {
        condition_stack.pop();
    }
}

std::string  Engine::popConditionStack() {
    std::string res = condition_stack.top();
    condition_stack.pop();
    return res;
}

std::string Engine::topConditionStack() {
    if(condition_stack.empty()) {
        return "";
    }
    return condition_stack.top();
}

bool Engine::isConditionStackEmpty() {
    return condition_stack.empty();
}

bool Engine::matchFacts(std::string ant, int contour_index) {
    ContourFact facts = this->facts_library["Contour" + std::to_string(contour_index)];
    bool matched = false;
    for(auto fact : facts.line_facts) {
        if( ant == fact.fact ) {
            matched = true;
            this->match_facts["Contour" + std::to_string(contour_index)].push_back(fact);
            return matched;
        }
    }
    for( auto fact : facts.angle_facts ) {
        if( ant == fact.fact ) {
            matched = true;
            this->match_facts["Contour" + std::to_string(contour_index)].push_back(fact);
            return matched;
        }
    }
    return matched;
}

bool Engine::hitConsequent(std::string cons, int contour_index) {
    bool hited = false;
    for(auto rule : this->rule_library) {
        if( cons == rule.consequent) {  
            hited = true;
            hit_rules["Contour"+std::to_string(contour_index)].push_back(rule);
            std::vector<std::string> ants = rule.antecedent;
            for(auto ant : ants) {
                if( !matchFacts(ant, contour_index)) {
                    pushConditionStack(ant);
                }
            }
            break;
        }
    }
    return hited;
}

void Engine::goal(std::string target) {
    target = target;
    clearConditionStack();
    match_facts.clear();
    hit_rules.clear();
    pushConditionStack(target);
}

std::string Engine::run(int contour_index) {
    match_facts["Contour" + std::to_string(contour_index)].clear();
    hit_rules["Contour" + std::to_string(contour_index)].clear();
    bool found = true;
    while(!condition_stack.empty()) {
        std::string condition = popConditionStack();
        if(!hitConsequent(condition, contour_index)) {
            found = false;
            break;
        }
    }
    clearConditionStack();
    condition_stack.push(target);

    if(found) {
        return "SUCCESS: Find Required Shape in Contour"+std::to_string(contour_index);
    }
    else {
        match_facts["Contour"+std::to_string(contour_index)].clear();
        hit_rules["Contour"+std::to_string(contour_index)].clear();
        return "ERROR: No Sufficient Facts in Contour"+std::to_string(contour_index);
    }
}

std::string Engine::getRuleLibrary() {
    std::string str;
    str += "\n";
    for(auto rule : rule_library) {
        str += rule.toString();
    }
    return str;
}

std::string Engine::toString() {
    std::string str;
    for(int i=0; i<60; i++) {
        str += "*";
    }
    str += "\n";
    str += "Shape Detection Engine -- a Rule-based Expert System\n";
    str += "--------------- Below is all the rules ---------------\n";
    str += getRuleLibrary();
    str += "---------------- End of all the rules ----------------\n";

    return str;
}



Rule generateRule(std::string rule) {
    /* if_part = ''
    exec('if_part = ' + re_if_part.findall(rule)[0])
    then_part = re_then_part.findall(rule)[0]
    description_part = re_description_part.findall(rule)[0]
    return Rule(if_part, then_part.strip('"\''), description_part.strip('"\'')) */

    std::vector<std::string> if_part;               // ? 
    std::string then_part, description_part;
    std::smatch if_match, then_match, description_match;
    
    std::regex_search(rule, if_match, re_if_part);
    if (if_match.size() >= 0) { 
        if_part[0] += if_match[0].str();
    }
    std::regex_search(rule, then_match, re_then_part);
    if (then_match.size() >= 0) {
        then_part = then_match[0].str();
    }
    std::regex_search(rule, description_match, re_description_part);
    if(description_match.size() >= 0) {
        description_part = description_match[0].str();
    }

    return Rule(if_part, then_part, description_part);
}

std::vector<Rule> separateRules(std::string rules) {
    std::smatch re_a_match;
    std::vector<std::string> rule_group;
    std::regex_match(rules, re_a_match, re_a_rule);
    for(int i = 0; i < re_a_match.size(); i++)  {
        rule_group.push_back(re_a_match[i].str());
    }
    std::vector<Rule> res;
    for(std::string rule : rule_group) {
        res.push_back(generateRule(rule));
    }
    return res;
}

std::vector<Rule> readRule(std::string rule_file) {
    std::string res;
    std::string line;
    std::ifstream file("../rules/" + rule_file);
    while(file >> line) {
        res += line;
    }
    return separateRules(res);
}

Engine setupEngine(std::string img_source) {
    Handler handler = Handler(img_source);
    handler.generateContour_dict();
    FactGenerator generator = FactGenerator(handler.contours_dict);
    generator.generateFact();
    std::vector<Rule> rules = readRule("rules.txt"); 
    Engine e = Engine(rules, generator.handled_facts);

    return e;
}

void setGoal(Engine e, std::string goal) {
    e.goal(goal);
}

std::tuple<std::vector<std::string>, std::map<std::string, std::vector<Fact>>, std::map<std::string, std::vector<Rule>>> mainRun(Engine e) {
    /*     
    results = []
    for i in range(len(e.fact_library)):
        result = e.run(i)
        results.append(result)
    return results, e.matched_facts, e.hit_rules 
    */

    std::vector<std::string> results;
    for(int i = 0; i < e.facts_library.size(); i++) {
        results.push_back(e.run(i));
    }
    return {results, e.match_facts, e.hit_rules};
}

