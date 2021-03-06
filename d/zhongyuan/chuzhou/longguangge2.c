// 楚州龙光阁顶层 /d/city/chuzhou/longguangge.c
// by lala, 1997-12-05

#define LOOK_CMD    "/cmds/std/look"

inherit ROOM;
#include <ansi.h>

int look_biaoju( object me );
int look_nanmen( object me );
int look_wuhuajie( object me );
int look_zhenchuyunhe( object me );

void create()
{
    set("short", WHT"龙光阁"NOR);
    set("long", @LONG
龙光阁上和文通塔上相差无多，也是充斥着登高望远观赏景致的人，不过由
于阁本身比塔顶宽大得多，阁中又有小几长凳，故而阁上的人又比塔上多得多了。
站在阁上，凭栏远眺，可以看到南城的扬威镖局、物华街、楚州南门和城外的真
楚运河。据说在天气晴好的时候，目力极佳的人可以一直看见扬州的城楼。
LONG
    );
    set("not_startroom", 1);
    set("no_kill",  "yangzhou");
    set("detail", ([
        "扬威镖局" : (:look_biaoju   :),
        "楚州南门" : (:look_nanmen   :),
        "物华街"   : (:look_wuhuajie :),
        "真楚运河" : (:look_zhenchuyunhe:),
    ]));        
    set("exits", ([
        "down"      : __DIR__"longguangge",
    ]));
    set("objects", ([
        __DIR__"npc/youke"  :   random(3),
    ]));
    setup();
}

int look_nanmen( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"nan_men") )
        ob = load_object(__DIR__"nan_men");
    message_vision(YEL"\n你极力远望，只看见：\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_wuhuajie( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"wuhua_jie") )
        ob = load_object(__DIR__"wuhua_jie");
    message_vision(YEL"\n你极力远望，只看见：\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_biaoju( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"biaoju") )
        ob = load_object(__DIR__"biaoju");
    message_vision(YEL"\n你极力远望，只看见：\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_zhenchuyunhe( object me )
{
    object ob;
    
    if( !ob = find_object("/d/zhongyuan/yunhe0") )
        ob = load_object("/d/zhongyuan/yunhe0");
    message_vision(YEL"\n你极力远望，只看见：\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}
