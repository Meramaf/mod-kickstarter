#!/usr/bin/env bash
MOD_KICKSTARTER_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/" && pwd )"

source $MOD_KICKSTARTER_ROOT"/conf/conf.sh.dist"

if [ -f $MOD_KICKSTARTER_ROOT"/conf/conf.sh" ]; then
    source $MOD_KICKSTARTER_ROOT"/conf/conf.sh"
fi
