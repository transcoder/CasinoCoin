// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    // How many times we expect transactions after the last checkpoint to
    // be slower. This number is a compromise, as it can't be accurate for
    // every system. When reindexing from a fast disk with a slow CPU, it
    // can be up to 20, while when downloading from a slow network with a
    // fast multicore CPU, it won't be much higher than 1.
    static const double fSigcheckVerificationFactor = 5.0;

    struct CCheckpointData {
        const MapCheckpoints *mapCheckpoints;
        int64 nTimeLastCheckpoint;
        int64 nTransactionsLastCheckpoint;
        double fTransactionsPerDay;
    };

    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (          0, uint256("0x4f46c9af6d88a14114b7dc53a37d81ba4064cda5ae2ede1213ca28fea9b86e9c"))
	    (          1, uint256("0xd6eea1064e9292f2a38e138bec64797914cff3189fbc6eaa2cc646c1514ccdfe"))
	    (        777, uint256("0x838c9d331811479957009c39d2e1e723d47ebd21453b3ad92bcabd6cb5dd6ab1"))
	    (       7777, uint256("0x09ab8471911e0f19e19ef09e1ae212b389f6be3e62f0c140d58c27084da08907"))
	    (      17777, uint256("0x4dd8c993bdb32b5ff63a1108f86b1cf2b6f3fb3e5a831d3445d944b986addadf"))
	    (      27777, uint256("0xea7623cc7d0db290b4f2bf5b1d5cbf477bf0c019b667d21dbc5e82e12adcf3ae"))
	    (      37777, uint256("0xced9dadf09278f513337ebbeee11804b794faddf8f759e583a1e39b0839c238a"))
	    (      47777, uint256("0xb59586840946941d9fd92dc378e0f2bd5fa4da0ebd0636dc009acc2a0174e048"))
	    (      57777, uint256("0xfdf6fa6f606f3b14e7b2084b0e60a80b769c2ae04fbea62d1af78674d3d1ef76"))
	    (      67777, uint256("0x5c6732d5ec60454ce68579cf88118923ebdd5dc82b372310bcf7d7303ffddf39"))
	    (      77777, uint256("0x4fa19ce5f0a050cbf13b3ad194c39351276a7e587ccdef03fa926429b00a0d44"))
	    (      87777, uint256("0x278d5a4d6ee24dfa263e33032ef0496e0e6d43d9f1918dc269dc83c56d29199c"))
	    (      97777, uint256("0xf1ab4d14a7a9797d4c22336aea6d83db6a2e5c7f07121d5b67b958e37ea5e384"))
	    (     107777, uint256("0x421ac0aed1cfb4226d4936fa0ac93c45cce9c6bec7aca4e329a672d8414b23ec"))
	    (     117777, uint256("0x731713bd84c9fd90cebc6c85c56cd071bd0826841fa1ff193250c9dd897650eb"))
	    (     127777, uint256("0xd90c1bb94b4aea5dcb4cb4a03de76190e7b1cf2e14fd45dc8a1e317066118491"))
	    (     137777, uint256("0x97972ecfc9efd19567f49c96f3bfaad15b3cc63ce0aac1780c1276624e41e9a2"))
	    (     147777, uint256("0xe83328402d705d53074cce0deb98f09b9016357063b522d30dbc450d241a073d"))
	    (     157777, uint256("0x86b45c6144bcdff90b2846e1669fdd49392e2c9eef6132184afc1a9434ef43a0"))
	    (     167777, uint256("0x065a4f24bf79b45353e456e74a75194be95d49bb9fbe2ef0771b0ff4a2c86ac6"))
	    (     177777, uint256("0x221fff51bd7a48c300b863ff5edb82dacf893ea908c00c4f6915789bed0d27b2"))
	    (     187777, uint256("0xad3c4d3b73493cb9c888b30f550db4fda6a5ff8c6daa20404285e354c3a4c7a1"))
	    (     197777, uint256("0x2f9203c38cede6e1c61a69eb43c4f62d8e04ba62a57a7d866f4d715eec033cd4"))
	    (     207777, uint256("0x3631874522954f18e6834ad68918dcc060b2712fea7a381e11e10193c6ab2f24"))
	    (     217777, uint256("0xc86150e3408be1ca10eb1b94f374ae331c07dec6e2162bf06f5c31d83faa9715"))
        ;
    static const CCheckpointData data = {
        &mapCheckpoints,
        1391536800, // * UNIX timestamp of last checkpoint block
        356643,    // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
        4500.0     // * estimated number of transactions per day after checkpoint
    };

    static MapCheckpoints mapCheckpointsTestnet = 
        boost::assign::map_list_of
        (     0, uint256("0x"))
        ;
    static const CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        1369685559,
        37581,
        300
    };

    const CCheckpointData &Checkpoints() {
        if (fTestNet)
            return dataTestnet;
        else
            return data;
    }

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints
        if (!GetBoolArg("-checkpoints", true))
            return true;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    // Guess how far we are in the verification process at the given block index
    double GuessVerificationProgress(CBlockIndex *pindex) {
        if (pindex==NULL)
            return 0.0;

        int64 nNow = time(NULL);

        double fWorkBefore = 0.0; // Amount of work done before pindex
        double fWorkAfter = 0.0;  // Amount of work left after pindex (estimated)
        // Work is defined as: 1.0 per transaction before the last checkoint, and
        // fSigcheckVerificationFactor per transaction after.

        const CCheckpointData &data = Checkpoints();

        if (pindex->nChainTx <= data.nTransactionsLastCheckpoint) {
            double nCheapBefore = pindex->nChainTx;
            double nCheapAfter = data.nTransactionsLastCheckpoint - pindex->nChainTx;
            double nExpensiveAfter = (nNow - data.nTimeLastCheckpoint)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore;
            fWorkAfter = nCheapAfter + nExpensiveAfter*fSigcheckVerificationFactor;
        } else {
            double nCheapBefore = data.nTransactionsLastCheckpoint;
            double nExpensiveBefore = pindex->nChainTx - data.nTransactionsLastCheckpoint;
            double nExpensiveAfter = (nNow - pindex->nTime)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore + nExpensiveBefore*fSigcheckVerificationFactor;
            fWorkAfter = nExpensiveAfter*fSigcheckVerificationFactor;
        }

        return fWorkBefore / (fWorkBefore + fWorkAfter);
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0; // Testnet has no checkpoints
        if (!GetBoolArg("-checkpoints", true))
            return 0;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL; // Testnet has no checkpoints
        if (!GetBoolArg("-checkpoints", true))
            return NULL;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
