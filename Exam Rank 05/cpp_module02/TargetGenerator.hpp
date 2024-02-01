#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"

class ATarget;

class TargetGenerator {

    public :
        TargetGenerator(){}

        ~TargetGenerator(){
            std::map<std::string, ATarget*>::iterator it = _tg.begin();
            for(; it != _tg.end(); it++)
                delete it->second;
            _tg.clear();
        }

        void learnTargetType(ATarget* tl) {
            if(tl)
                _tg.insert(std::pair<std::string,ATarget*>(tl->getType(),tl->clone()));
        }

        void forgetTargetType(std::string const &s){
            if(_tg.find(s) != _tg.end()){
                delete _tg.find(s)->second;
                _tg.erase(_tg.find(s));
            }
        }

        ATarget* createTarget(std::string const &s){
            if(_tg.find(s) != _tg.end())
                return _tg[s];
            return NULL;
        }

    private:
        std::map<std::string, ATarget*>_tg;
        TargetGenerator(TargetGenerator const &src);
        TargetGenerator & operator=(TargetGenerator const &rhs);

};
