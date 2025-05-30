// CMakeProject2.cpp: определяет точку входа для приложения.
//

#include "CMakeProject2.h"

#include <memory>

#include "Test.h"
#include "ModelCommunication/ModelCommunication.h"

void run() {
    using namespace communicate;
    std::unique_ptr<ModelCommunication> communicate 
        = std::make_unique<ModelCommunication>();

    communicate->Start();
}

int main()
{
    //cpr_requests_test();
    //mistral_request();
    //mistral_test();

    //communicate::ModelCommunication modelCommunicate{};
    //modelCommunicate.StartDialogue();

    //do_tree();

    
    //actions_ruls_test();
    //balancing_tree_test();

    //input_request_data_test();

    //test_prev_actions();

    //test_user_action();

    //test_request();

    //test_response();

    run();

	return 0;
}
