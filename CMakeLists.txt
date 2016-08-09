cmake_minimum_required(VERSION 2.8)
project(ATM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(atm atm/physical atm/transaction banking)

set(SOURCE_FILES main_app.cpp
	atm/ATM.cpp atm/ATM.h
	atm/Session.h atm/Session.cpp

	atm/physical/CardReader.cpp atm/physical/CardReader.h
	atm/physical/CashDispenser.h atm/physical/CashDispenser.cpp
	atm/physical/EnvelopeAcceptor.h
	atm/physical/NetworkToBank.h atm/physical/NetworkToBank.cpp
	atm/physical/OperatorPanel.h
	atm/physical/ReceiptPrinter.h
	atm/physical/CustomerConsole.h

	atm/transaction/Transaction.h atm/transaction/Transaction.cpp
	atm/transaction/Deposit.h atm/transaction/Deposit.cpp
	atm/transaction/Inquiry.h atm/transaction/Inquiry.cpp
	atm/transaction/Transfer.h atm/transaction/Transfer.cpp
	atm/transaction/Withdrawal.h atm/transaction/Withdrawal.cpp

	banking/AccountInformation.h
	banking/Log.h banking/Log.cpp
	banking/Balances.h
	banking/Card.h
	banking/Message.h
	banking/Money.h
	banking/Status.h
	banking/Receipt.h banking/Receipt.cpp

	)
add_executable(atm_simutation ${SOURCE_FILES})
