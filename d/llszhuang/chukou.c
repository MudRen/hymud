// chukou.c

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "Ĺ��");
  set("long",
"������ɥ����ɽׯ��Ľ������͵�Ĺ��,һ���Ĺ��(mubei)����·��\n"
".\n�ƺ����ڸ������������RED~~~ǧ��ҪС�İ�!~~~NOR\n"
);
        set("item_desc", ([
            "mubei": HIG "\n����д��--�Ͽ��߰�,���ﲻ�Ǿ���֮�ذ�!(leave here)\n" NOR,
    ]));
        set("no_fight",1);
        set("no_die",1);
        setup();
}

int init()
{
        add_action("do_leave","leave");
}
int do_leave(string arg)
{
        object me;
        object *inv;
        int i;
        me = this_player();
        inv = all_inventory(me);
    if ( !arg || arg !="here" )
        return notify_fail("�����Ҫ��?��leave here \n");

        for( i=0;i<sizeof(inv);i++)
{
                if( inv[i]->is_character() )
                   return notify_fail("�㲻�ܱ����˽�ȥ!\n");
}
       write(YEL"�������뿪�����ط�!\n"NOR);
        me->move(__DIR__"gate");
        return 1;
}

