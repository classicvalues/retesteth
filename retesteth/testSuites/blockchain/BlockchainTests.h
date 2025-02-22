/** @file BlockchainTests.h
 * BlockchainTests functions.
 */

#pragma once
#include <dataObject/DataObject.h>
#include <retesteth/Options.h>
#include <retesteth/TestHelper.h>
#include <retesteth/TestSuite.h>
#include <retesteth/testSuites/TestFixtures.h>
#include <boost/filesystem/path.hpp>

namespace test
{

/// Suite run and check blockchain tests with valid blocks only
class BlockchainTestValidSuite : public TestSuite
{
public:
    spDataObject doTests(spDataObject& _input, TestSuiteOptions& _opt) const override;
    TestPath suiteFolder() const override;
    FillerPath suiteFillerFolder() const override;
};

/// Suite run/check generate blockchain tests that has malicious blocks
class BlockchainTestInvalidSuite : public TestSuite
{
public:
    spDataObject doTests(spDataObject& _input, TestSuiteOptions& _opt) const override;
    TestPath suiteFolder() const override;
    FillerPath suiteFillerFolder() const override;
};

/// Suite run/check blockchain tests with fork transition configurations
class BlockchainTestTransitionSuite : public TestSuite
{
public:
    spDataObject doTests(spDataObject& _input, TestSuiteOptions& _opt) const override;
    TestPath suiteFolder() const override;
    FillerPath suiteFillerFolder() const override;
};

/// Suite run/check stateTests converted into blockchain by testeth
class BCGeneralStateTestsSuite : public BlockchainTestValidSuite
{
    test::TestSuite::TestPath suiteFolder() const override;
    test::TestSuite::FillerPath suiteFillerFolder() const override;
public:
    BCGeneralStateTestsSuite() {
        TestInfo errorInfo("Initialized ", "BCGeneralStateTestsSuite");
        TestOutputHelper::get().setCurrentTestInfo(errorInfo);
    }
};

class BCGeneralStateTestsVMSuite : public BCGeneralStateTestsSuite
{
public:
    BCGeneralStateTestsVMSuite();
    test::TestSuite::TestPath suiteFolder() const override;
    test::TestSuite::FillerPath suiteFillerFolder() const override;
};

/// Suite run/check stateTests converted into blockchain by testeth
class LegacyConstantinopleBCGeneralStateTestsSuite : public BlockchainTestValidSuite
{
protected:
    bool legacyTestSuiteFlag() const override { return  true; }
public:
    spDataObject doTests(spDataObject& _input, TestSuiteOptions& _opt) const override;
    test::TestSuite::TestPath suiteFolder() const override;
    test::TestSuite::FillerPath suiteFillerFolder() const override;
};


class LegacyConstantinopleBlockchainInvalidTestSuite : public BlockchainTestInvalidSuite
{
protected:
    bool legacyTestSuiteFlag() const override { return  true; }
public:
    spDataObject doTests(spDataObject& _input, TestSuiteOptions& _opt) const override;
    TestPath suiteFolder() const override
    {
        return TestSuite::TestPath(
            fs::path("LegacyTests/Constantinople/BlockchainTests/InvalidBlocks"));
    }
    FillerPath suiteFillerFolder() const override
    {
        return TestSuite::FillerPath(
            fs::path("/src/LegacyTests/Constantinople/BlockchainTestsFiller/InvalidBlocks"));
    }
};

class LegacyConstantinopleBlockchainValidTestSuite : public BlockchainTestValidSuite
{
protected:
    bool legacyTestSuiteFlag() const override { return  true; }
public:
    spDataObject doTests(spDataObject& _input, TestSuiteOptions& _opt) const override;
    TestPath suiteFolder() const override
    {
        return TestSuite::TestPath(
            fs::path("LegacyTests/Constantinople/BlockchainTests/ValidBlocks"));
    }
    FillerPath suiteFillerFolder() const override
    {
        return TestSuite::FillerPath(
            fs::path("/src/LegacyTests/Constantinople/BlockchainTestsFiller/ValidBlocks"));
    }
};

}  // test
