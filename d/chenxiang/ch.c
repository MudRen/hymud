 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
ÿ�������۴�С���и��������Ҳ�����⡣����Ȼ����
���ȴ����ʢ��������˴��ϵ��ٶ����ϣ�������ڵ�ʱ������
�Ͱ����˸��ָ����ļ�Ʒ��
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "east" : __DIR__"cxs2",
        ]));
    set("objects", ([
        __DIR__"npc/omonk": 1, 
        ]) );
    set("coor/x",-510);
    set("coor/y",-530);
    set("coor/z",0);
    setup();
} 
void init()
{
    add_action("do_ask","ask");
} 
int do_ask(string arg)
{
    object me,obj;
    string aa,bb;
    me = this_player();
    if(!query("marks/gone") && me->query_temp("marks/huier"))
    {
        if(!stringp(arg)) return 0;
        if(sscanf(arg,"%s about %s",aa,bb) != 2) return 0;
        if( aa != "��ү" &&  aa != "jiuye") return 0;
        if( bb != "ӡ" && bb != "yin") return 0;
        set("marks/gone",1);
        obj = new(__DIR__"obj/yin");
        obj->set("huier",1); 
        obj->move(this_object());
        tell_object(me,"��ֻ������ž����һ������һ�������ӷ�������������\n");
        return 1;
    }
    return 0;
} 
void reset()
{
    ::reset();
    delete("marks/gone");
}    
