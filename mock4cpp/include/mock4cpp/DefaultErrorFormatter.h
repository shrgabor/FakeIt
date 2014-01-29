/*
 * DefaultErrorFormatter.h
 *
 *  Created on: Jan 29, 2014
 *      Author: eran
 */

#ifndef DEFAULTERRORFORMATTER_H_
#define DEFAULTERRORFORMATTER_H_

#include <vector>
#include "mock4cpp/ErrorFormatter.h"

struct DefaultErrorFormatter: public virtual ErrorFormatter {
	virtual ~DefaultErrorFormatter() = default;

	virtual std::string buildNoOtherInvocationsVerificationErrorMsg( //
			std::vector<AnyInvocation*>& allIvocations, //
			std::vector<AnyInvocation*>& unverifedIvocations) override {

		auto format = std::string("found ") + std::to_string(unverifedIvocations.size()) + " non verified invocations.\n";
		for (auto invocation : unverifedIvocations) {
			format += invocation->format();
			format += '\n';
		}
		return format;
	}

	virtual std::string buildExactVerificationErrorMsg(std::vector<Sequence*>& expectedPattern, std::vector<AnyInvocation*>& actualSequence,
			int expectedInvocationCount, int count) override {
		return std::string("expected ") + std::to_string(expectedInvocationCount) + " but was " + std::to_string(count);
	}

	virtual std::string buildAtLeastVerificationErrorMsg(std::vector<Sequence*>& expectedPattern,
			std::vector<AnyInvocation*>& actualSequence, int expectedInvocationCount, int count) override {
		return std::string("Expected invocation scenario does not match actual invocation order");
	}
}static defaultErrorFormatter;


#endif /* DEFAULTERRORFORMATTER_H_ */
