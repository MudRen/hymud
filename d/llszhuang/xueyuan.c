#include <combat.h>
#include <ansi.h>
inherit ROOM;
string *all_dirs = ({"north","south","east","west","southwest","northeast","southeast","northwest"});
void create()
{
        set("short", "ѩԭ");
        set("long",
"������һƬ�����ѩ�أ����֮��һƬ��ã�������㼣ԶԶ�������\n"
"ȥ���ƺ����޾�ͷ����ʱ����������������������Х�͡���������Ц����\n"
);
        set("no_magic", "1");

        set("exits", ([ /* sizeof() == 2 */
          "north" : __FILE__,
          "south" : __FILE__,
          "east" : __FILE__,
          "west" : __FILE__,
          "southeast" : __FILE__,
          "southwest" : __FILE__,
          "northeast" : __FILE__,
        "northwest" : __FILE__,
        ]));

        set("objects", ([
                //      __DIR__"npc/roc" : 1,
                ])
        );
        setup();
}

int valid_leave(object ob,string dir)
{
        object roc;

        switch(random(15))
        {
                case 1:
                case 2:
                case 3:
                        message_vision(RED"\n����ѩ֮�У��ƺ���ʲô����������һ�Ӷ�����"NOR,ob);
                        roc = new("/d/llszhuang/npc/roc");
                        roc->move(environment(ob));
                        COMBAT_D->do_attack(roc,ob,roc->query_temp("weapon"),TYPE_QUICK);
                      message_vision(YEL"��ڤ��������Х������ת����ʧ���Ʋ��С�\n\n"NOR,ob);
                        destruct(roc);
                        return 1;
                default:
                        if( dir == all_dirs[random(4)] )
                                ob->add_temp("doom_trigger",1);
                        if( dir == all_dirs[4+random(4)] )
                                ob->add_temp("doom_trigger",-1);

                        if( ob->query_temp("doom_trigger") == 3)
                        {
                     message("channel:chat", YEL"���������¡��������ԣ�"+ob->name()+"��ĳһ��ͻȻ����������ɽׯ��\n"NOR,users());
                                ob->move(__DIR__"gate");
                                ob->delete_temp("doom_trigger");
                                return notify_fail("�������ҵ��˳��ڣ�����������ɽׯ�����š�\n");
                        }


                        if( ob->query_temp("doom_trigger") == -3)
                        {
                                write("�������ҵ�����ʱ��·���ɹ���С�ӣ�ѭԭ·�ء�\n");
                                ob->move(__DIR__"dukou");
                                ob->delete_temp("doom_trigger");
                              return notify_fail("�������ҵ�����ʱ��·���ɹ���С�ӣ�ѭԭ·�ص��˶ɿڡ�\n");
                        }

                        return 1;
        }

}

