//1997-3-10 by qyz
#include <room.h>
#include <ansi.h>

inherit ROOM;


void create()
{
	set("short","����·");
	set("long",@LONG
�ڹ⻬���±��ϣ�������һ�������ų��������ݣ������ɽ�紵��ʱ��
�ڶ���ײ��ʯ���Ϸ��������ϵ����������˲����������¶�����һ����������
��ջ����һ�����£�һ�����գ��ø�ǥ�����±ڣ����ϼ�Щľ�壬ʮ���վ�����
�����أ�ľ����һͷ�����𣬰����ŵ�ɥ��ʧ�ǡ����Գ�����Ϊ��������ˣ�˭
Ҳ���������±�ȥ��
LONG);
	set("not_startroom",1);
	set("exits",
	([
             "down" : __DIR__"xianren_qiao",
//             "up" : __DIR__"xuanhe_dong",
          	]));
        set("outdoors","kongdong");
	set("objects",([
		__DIR__"npc/zhou" : 1,
		]) );
        setup();
        //place_program(ROOM);
}
void init()
{
	add_action("do_climb","climb");
	add_action("do_update","update");	
	}
int do_update()
{return 1;}
int do_climb(string arg)
{
        object *all;
                int i;
	object me =this_player();
	
	if(!arg||arg!="ջ��")
	return notify_fail("��Ҫ������ȥ���ɲ���������ģ�\n");
	if(me->query_temp("climbing"))
	return notify_fail("������սս�����ع�ջ���أ�\n");

       all=all_inventory(me);
            for(i=0;i<sizeof(all);i++)
                if(userp(all[i])){
                    message_vision("$N��$n������һˤ���¸ҵ�������ȥ��\n",me,all[i]);
                    all[i]->move(__DIR__"yiwu_lu");
                }        
    me->start_busy(30);
	call_out("pashan", 5, me, 0);
	me->set_temp("climbing",1);
        message_vision( HIG"$N�������˼����������Ų������Ƶ�ջ�����˹�ȥ......\n"NOR ,me);
	return 1;

}
	
void pashan( object me, int number )
{
	object *inv;
int i,j;
object dong =load_object(__DIR__"xuanhe_dong");  
i=number + 1;
switch( i ) {
case 1:
case 2:
case 3:
case 4:
message_vision( HIR"$N������һ��һ������ǰŲ......\n"NOR ,me);
break;
case 5:
message_vision( HIG"�ۿ�$N�Ѿ�����ջ��������......\n"NOR,me );
break;
case 6:
case 7:
case 8:
case 9:
message_vision( HIR"$N������һ��һ������ǰŲ......\n"NOR ,me);
break;
default:
if( !random(5) || me->query("id")=="zhou zhenren" )
{
message_vision( HIG"���ڣ�$N�����˶����ʯ��....����ѽ��\n",me);
me->move(__DIR__"xuanhe_dong");
inv = all_inventory(this_object());
for (j = 0; j < sizeof(inv); j++)
  if (userp(inv[j]))
  inv[j]->set("marks/kongdong/zhou",1);
return;	
	}
message_vision( HIY"ͻȻһ�����ģ�$N����һ�ߣ��������ξ͵�����ȥ.....\n"NOR, me);
if( me->query_skill("dodge",1)>200&&present("zhou zhenren",dong)&&random(me->query_kar())>28)
{message_vision( HIG"ʯ�ڶ�����������׳�һ�����������ò���$N�����䣬��$N������ȥ....����ѽ��\n"NOR,me );
me->move(__DIR__"xuanhe_dong");
}
else
{message_vision( HIY"ֻ��$Nһ��ҽУ���׹��������Ԩ......\n"NOR,me);
me->set("eff_jing",me->query("eff_jing")/2);
me->move(__DIR__"xiangtou_ya");
me->delete_temp("climbing");
if(!userp(me))
destruct(me);
else if(me->query("eff_jing")<me->query("max_jing")/6)
me->die();
else
me->unconcious();
}
return;
}
call_out( "pashan", 5, me, i );
return;
}
/*
int valid_leave(object me,string dir)
{
    if(dir=="up")
      return notify_fail("ֻ������ջ�������߹�ȥ�ģ����Գ���(climb ջ��)��\n");
    return ::valid_leave(me,dir);
}
*/