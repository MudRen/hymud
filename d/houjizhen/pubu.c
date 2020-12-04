// pubu.c
// by dicky

inherit ROOM;
#include <ansi.h>
#include <command.h>
string look_chi();

void create()
{
        set("short",HIW "�ٲ�" NOR);
        set("long", @LONG
ɽ��СϪ�������ϣ���ǰ��Ȼ����һ����к���µ��ٲ���������ɽ��ˮ��
���󣬾������������������˴�����Ȼ�������ͱ��ϵ�ˮֱк������һ����
����������������������ˮ����������ȵף������ɸߵİ��ˣ�ǡ������
ѩ�����ӹ�����һ�㡣����ˮ���ļ��Ҵ˵س�ů����˲��������
LONG
);
        set("outdoors", "houjizhen");
        set("item_desc",([            
            "pool" : (: look_chi :),
        ]));
        set("exits", ([ 
          "eastdown" : __DIR__"xiaoxi1",
          ]));


        setup();
}

void init()
{
        add_action("do_jump", "xi");
}

int do_jump(string arg)
{
        int i, j;
        object me, room, *ob, *inv;
        me = this_player();

        if (!(room = find_object(__DIR__"chi")))
              room = load_object(__DIR__"chi");
        ob = all_inventory(room);
        j = sizeof(ob);

	if(!living(me) ) return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");

	if( !arg || arg == "" || arg != "pool" )
		return notify_fail("��Ҫ��ʲô��\n");
        
	if((me->query_encumbrance()*20) > me->query_max_encumbrance() && !wizardp(me))
		return notify_fail("�����ϵĶ���̫���ˣ�\n");




        tell_object(me, GRN "���ߵ��رߣ���ȥ�����Ҫ����ԡ�ɳء�\n"NOR);
        tell_room(environment(me), me->name()+"ת���ߵ��رߣ�������Ҫ����������ˮȥ��\n", ({ me }));
       if(j>0){
       if(j>1)
            return notify_fail(HIR"��ͻȻ���ֳ�ˮ�����ˣ����һ���ֹһ��������æ���˻�����\n"NOR);
            tell_object(me, "��ͻȻ���ֳ�ˮ�����ˣ�\n");
               for(i=0; i<sizeof(ob); i++) {
                 if(!living(ob[i])) continue;
                 if(me->query("gender") == ob[i]->query("gender")){
                   if(me->query("gender") == "Ů��")
                       tell_object(me, "����һ����ԭ��Ҳ�Ǹ�Ů�ӡ�������һЦ����������ˮȥ��\n");
                   if(me->query("gender") =="����")
                       tell_object(me, "����һ����ԭ��Ҳ�Ǹ����ӡ�������һ�£���������ˮȥ��\n");
                   tell_room(environment(me), me->name()+"ת���ߵ��رߣ�������Ҫ����������ˮȥ��\n", ({ me })); 
                   me->move(__DIR__"chi");
                   return 1;
                   }
                 else{ 
                   tell_object(me, "����һ����ԭ���Է���λ��������������һ�죬��æ�����·����˻�����\n");
                   tell_room(environment(me), me->name()+"ת���ߵ��رߣ�����һ�٣������˻�����\n", ({ me })); 
                   }
                }
        return 1; 
        } 
    me->move(__DIR__"chi");
    return 1;
}

string look_chi()
{
	object me, room;
	me = this_player();
	if (!(room = find_object(__DIR__"chi")))
	     room = load_object(__DIR__"chi");

	return "������ϴ�裬�������￴ʲô����Ҳ��������";
}