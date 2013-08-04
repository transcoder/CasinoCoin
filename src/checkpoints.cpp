// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 CasinoCoin Developers
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

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (     0, uint256("0x4f46c9af6d88a14114b7dc53a37d81ba4064cda5ae2ede1213ca28fea9b86e9c"))
	    (     1, uint256("0xd6eea1064e9292f2a38e138bec64797914cff3189fbc6eaa2cc646c1514ccdfe"))
	    (     777, uint256("0x838c9d331811479957009c39d2e1e723d47ebd21453b3ad92bcabd6cb5dd6ab1"))
	    (     7777, uint256("0x09ab8471911e0f19e19ef09e1ae212b389f6be3e62f0c140d58c27084da08907"))
	    (     17777, uint256("0x4dd8c993bdb32b5ff63a1108f86b1cf2b6f3fb3e5a831d3445d944b986addadf"))
	    (     27777, uint256("0xea7623cc7d0db290b4f2bf5b1d5cbf477bf0c019b667d21dbc5e82e12adcf3ae"))
	    (     37777, uint256("0xced9dadf09278f513337ebbeee11804b794faddf8f759e583a1e39b0839c238a"))
        ;

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;

        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
