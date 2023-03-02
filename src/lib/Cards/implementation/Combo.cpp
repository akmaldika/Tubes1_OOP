#include "../header/Combo.hpp"

Combo::Combo(vector<Card> combination){
    for (auto i= combination.begin(); i!=combination.end(); i++){
        this->combination.push_back(*i);
    }
    this->type = "unknown";
}

void setCombinationType(){
    // Mencari jenis combinasi

}

double Combo::value(){
    if (this->type == "unknown"){
        setCombinationType();
    }
    if (this->type == "Pair"){

    } else if (this->type == "Two Pair"){

    } else if (this->type == "Three of a Kind"){

    } else if (this->type == "Straight"){

    } else if (this->type == "Flush"){

    } else if (this->type == "Full House"){

    } else if (this->type == "Four of a Kind"){

    } else if (this->type == "Straight Flush"){

    }
}