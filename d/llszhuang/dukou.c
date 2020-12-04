#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���ֶ�");
        set("long",
"������ǰ������ɽׯ�ıؾ�֮·��һ��С�Ӻ��������ǰ���������\n"
"������һ������ɿ��Ա�һ�����õĲ����������ϣ��ײ��ڱ����з��裬\n"
"�㶨��һ��������д�ż���Ѫ�֣�\n"
HIR "                    һ��˾������޹�·\n" NOR
);

        set("exits", ([ /* sizeof() == 2 */
          "south" : __DIR__"inn",
          "north" : __DIR__"xueyuan",
        ]));    
        set("no_fight",1);                                 
       set ("no_look",1);
        setup();
}                                  

int init()
{
          add_action("do_north","gonorth");
}                

int valid_leave(object me,string dir)
{
        if( dir == "north" )
                return notify_fail(
                        "\n��Ҫ��ȥ�������Ҫ��ȥ����ò�������Ҫ��ȥ�ɡ�\n"        
                        "��Ҫ��ȥ��˵���Ȼ����г���������ǻ������\n"
                        "�����㲻˵������ô֪����Ҫ��ȥ�أ������Ҫ��ȥ��\n"
                          "��Ҫ��ȥ�����gonorth�ɡ�\n\n"
                );
        return 1;
}

int do_north(string arg)
{
        object me;
        object *inv;
        int i;

        me = this_player();

        inv = all_inventory(me);
        for( i=0;i<sizeof(inv);i++) 
        {
                if( inv[i]->is_character() )
                {
                        write("�㲻�ܱ���"+inv[i]->query("name")+"��ȥ!\n");    
                        return 1;
                }
        }

         if (me->query("combat_exp") < 800000)
        {       
                write(RED"ǰ��·;�ն񣬻��ǲ�Ҫȥ�����˰ɡ�\n"NOR);
                return 1;
        }

        write(YEL"������������ɹ���ȥ��̤�����ն�����̡�\n"NOR);
        this_player()->move(__DIR__"xueyuan");

        return 1;
}

