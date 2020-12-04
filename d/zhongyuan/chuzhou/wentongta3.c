// ������ͨ������ /d/city/chuzhou/wentongta3.c
// by lala&lnwm, 1997-12-05

#define LOOK_CMD    "/cmds/verb/look"

inherit ROOM;
#include <ansi.h>

int look_dukou( object me );
int look_diaotai( object me );
int look_beimen( object me );
int look_tianbaolu( object me );
int look_beishi( object me );
int look_fumaxiang( object me );

void create()
{
    set("short", WHT"��ͨ��"NOR);
    set("long", @LONG
��ͨ���Ķ����Ͼ�Ȼ�в��ٵ����ˣ����Ƕ��������˱����������ݳǵķ�⣬
Ҳ��Щ�˽����������ӻ��Ӷɿڵ�����Ĵ�·��������û���Լ����ڵȴ����ˡ�
����������Կ������Ӷɿڡ���̨�����ݱ��š��챦·�������Լ�������������
��һ�����顣
LONG
    );
    set("not_startroom", 1);
    set("no_kill",  "yangzhou");
    set("detail", ([
        "���Ӷɿ�" : (:look_dukou    :),
        "��̨"     : (:look_diaotai  :),
        "���ݱ���" : (:look_beimen   :),
        "�챦·"   : (:look_tianbaolu:),
        "����"     : (:look_beishi   :),
        "������"   : (:look_fumaxiang:),
    ]));        
    set("exits", ([
        "down"      : __DIR__"wentongta2",
    ]));
    set("objects", ([
    ]));
    setup();
}

int look_dukou( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"dukou") )
        ob = load_object(__DIR__"dukou");
    message_vision(YEL"\n�㼫��Զ����ֻ������\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_diaotai( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"diaotai") )
        ob = load_object(__DIR__"diaotai");
    message_vision(YEL"\n�㼫��Զ����ֻ������\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_beimen( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"bei_men") )
        ob = load_object(__DIR__"bei_men");
    message_vision(YEL"\n�㼫��Զ����ֻ������\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_tianbaolu( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"tianbao_lu") )
        ob = load_object(__DIR__"tianbao_lu");
    message_vision(YEL"\n�㼫��Զ����ֻ������\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_beishi( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"beishi") )
        ob = load_object(__DIR__"beishi");
    message_vision(YEL"\n�㼫��Զ����ֻ������\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}

int look_fumaxiang( object me )
{
    object ob;
    
    if( !ob = find_object(__DIR__"fuma_xiang") )
        ob = load_object(__DIR__"fuma_xiang");
    message_vision(YEL"\n�㼫��Զ����ֻ������\n\n"NOR,me);
    LOOK_CMD->look_room(me, ob);
    return 1;
}
