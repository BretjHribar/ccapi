#ifndef INCLUDE_CCAPI_CPP_SERVICE_CCAPI_EXECUTION_MANAGEMENT_SERVICE_HUOBI_COIN_SWAP_H_
#define INCLUDE_CCAPI_CPP_SERVICE_CCAPI_EXECUTION_MANAGEMENT_SERVICE_HUOBI_COIN_SWAP_H_
#ifdef CCAPI_ENABLE_SERVICE_EXECUTION_MANAGEMENT
#ifdef CCAPI_ENABLE_EXCHANGE_HUOBI_COIN_SWAP
#include "ccapi_cpp/service/ccapi_execution_management_service_huobi_derivatives_base.h"
namespace ccapi {
class ExecutionManagementServiceHuobiCoinSwap : public ExecutionManagementServiceHuobiDerivativesBase {
 public:
  ExecutionManagementServiceHuobiCoinSwap(std::function<void(Event& event)> eventHandler, SessionOptions sessionOptions, SessionConfigs sessionConfigs,
                                          ServiceContextPtr serviceContextPtr)
      : ExecutionManagementServiceHuobiBase(eventHandler, sessionOptions, sessionConfigs, serviceContextPtr) {
    CCAPI_LOGGER_FUNCTION_ENTER;
    this->exchangeName = CCAPI_EXCHANGE_NAME_HUOBI_COIN_SWAP;
    this->baseUrlRest = this->sessionConfigs.getUrlRestBase().at(this->exchangeName);
    this->setHostRestFromUrlRest(this->baseUrlRest);
    try {
      this->tcpResolverResultsRest = this->resolver.resolve(this->hostRest, this->portRest);
    } catch (const std::exception& e) {
      CCAPI_LOGGER_FATAL(std::string("e.what() = ") + e.what());
    }
    this->apiKeyName = CCAPI_HUOBI_COIN_SWAP_API_KEY;
    this->apiSecretName = CCAPI_HUOBI_COIN_SWAP_API_SECRET;
    this->setupCredential({this->apiKeyName, this->apiSecretName});
    this->createOrderTarget = CCAPI_HUOBI_COIN_SWAP_CREATE_ORDER_TARGET;
    this->cancelOrderTarget = CCAPI_HUOBI_COIN_SWAP_CANCEL_ORDER_TARGET;
    this->getOrderTarget = CCAPI_HUOBI_COIN_SWAP_GET_ORDER_TARGET;
    this->getOpenOrdersTarget = CCAPI_HUOBI_COIN_SWAP_GET_OPEN_ORDERS_TARGET;
    CCAPI_LOGGER_FUNCTION_EXIT;
  }
  virtual ~ExecutionManagementServiceHuobiCoinSwap() {}
};
} /* namespace ccapi */
#endif
#endif
#endif  // INCLUDE_CCAPI_CPP_SERVICE_CCAPI_EXECUTION_MANAGEMENT_SERVICE_HUOBI_COIN_SWAP_H_
