// Room: /d/tianshui/chaguan.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "���ݲ��");
	set("long", @LONG
��˵�������μ�ª����һ����������Ƣ�Ĳ����˱Ƕ�����ʹ
�˾���Ϊ֮һˬ�����������˿��ˣ��еĸ�̸���ۣ��еĽ�ͷ��
����Ҫ�����ʲô���飬������������ʡ�
LONG
	);
        set("night_long", @LONG
�����Ѿ������ˡ������Ͽտյģ�ֻ�����δ����ǡ���ʦ��
���ڽ����һ��������˯�ţ��������˽������Ͻ�վ��������
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"sroad1",
]));

	
        set("no_sleep_room",1);

        set("objects",([
        __DIR__"npc/teaboss" : 1,
]));

	setup();
}

void open_close_door(string msg,object user)
{
        object ob = present("tea boss",this_object());
 
        if(!msg || !user)
                return;
        if( msg == "begin_day")
        {
                if(ob)
                        tell_object(user,CYN"��ʦЦӯӯ�Ķ���˵�����͹������������Ӫҵ�ˣ���"+
                        RANK_D->query_respect(user)+"�����⡣\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"��ʼӪҵ�ˡ�\n"NOR);
                return;
        }

        else if( msg == "begin_night")
        {
                if(ob)
                        tell_object(user,CYN"��ʦ��ͷ������˵������λ"+
                        RANK_D->query_respect(user)+"�Բ���С�Ŵ����ˣ����������������ɡ�\n"NOR);
                else
                        tell_object(user,CYN ""+query("short")+"�����ˡ�\n"NOR);
                return;
        }
}
