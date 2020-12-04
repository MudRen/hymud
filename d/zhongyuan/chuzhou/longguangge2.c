// ��������󶥲� /d/city/chuzhou/longguangge.c
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
    set("short", WHT"�����"NOR);
    set("long", @LONG
������Ϻ���ͨ��������޶࣬Ҳ�ǳ���ŵǸ���Զ���;��µ��ˣ�������
�ڸ�����������ö࣬��������С�����ʣ��ʶ����ϵ����ֱ����϶�ö��ˡ�
վ�ڸ��ϣ�ƾ��Զ�������Կ����ϳǵ������ھ֡��ﻪ�֡��������źͳ������
���˺ӡ���˵��������õ�ʱ��Ŀ�����ѵ��˿���һֱ�������ݵĳ�¥��
LONG
    );
    set("not_startroom", 1);
    set("no_kill",  "yangzhou");
    set("detail", ([
        "�����ھ�" : (:look_biaoju   :),
        "��������" : (:look_nanmen   :),
        "�ﻪ��"   : (:look_wuhuajie :),
        "����˺�" : (:look_zhenchuyunhe:),
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
    message_vision(YEL"\n�㼫��Զ����ֻ������\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_wuhuajie( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"wuhua_jie") )
        ob = load_object(__DIR__"wuhua_jie");
    message_vision(YEL"\n�㼫��Զ����ֻ������\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_biaoju( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"biaoju") )
        ob = load_object(__DIR__"biaoju");
    message_vision(YEL"\n�㼫��Զ����ֻ������\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_zhenchuyunhe( object me )
{
    object ob;
    
    if( !ob = find_object("/d/zhongyuan/yunhe0") )
        ob = load_object("/d/zhongyuan/yunhe0");
    message_vision(YEL"\n�㼫��Զ����ֻ������\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}
