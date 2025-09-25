// PluginHelpers.h
// https://raw.githubusercontent.com/thomas4f/mxbmrp2/refs/heads/master/mxbmrp2/PluginHelpers.h

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "ConfigManager.h"
/*uc*///#include "MemReaderHelpers.h"

namespace PluginHelpers {

    std::vector<std::string> buildDisplayStrings(
        const std::unordered_map<std::string, std::string>& allDataKeys,
        const std::vector<std::pair<std::string, std::string>>& configKeyToDisplayNameMap,
        ConfigManager& configManager,
        size_t maxLength
    );

    /*uc*///using ByteBuf = MemReaderHelpers::ByteBuf;

    // Converts game state
    std::string getGameState(int gameState);

    // Converts event type
    std::string getEventType(int type, const std::string& connectionType);

    // Converts session and type
    std::string getSessionType(int type, int session);

    // Converts session state
    std::string getSessionState(int sessionState);

    // Returns session duration
    std::string getSessionDuration(int numLaps, int sessionLenMs, int sessionTimeMs);

    // Converts numeric conditions
    std::string getConditions(int condition);

    // Formats an IPv6-mapped IPv4 address
    /*uc*///std::string formatIPv6MappedIPv4(const ByteBuf& ipv6);

    // Builds a connection string
    std::string buildConnectURIString(const std::string& formattedIPv6,
        const std::string& serverName,
        const std::string& password,
        const std::string& trackID,
        const std::string& serverCategories);

    // Extracts the server name from the connection string
    std::string getServerNameFromConnectURI(const std::string& connStr);

} // namespace PluginHelpers