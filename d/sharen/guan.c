 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "蜡人阁");
        set("long", @LONG
一个密封的石室，到处都是血腥的味道，空气彷佛已经凝固，让
人非常压抑。室内靠墙的地方都摆着蜡像，有些已经发黄。只有当中
一个安放在一张石椅上，目不转睛地看着你，看得你有点心慌慌。这
里虽然没有让人呕吐的杀气，但你还是想尽快离开。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */

  "east" : __DIR__"caodi",

   ]));



        set("objects", ([
       
//        __DIR__"npc/bandit1" : 5,
                        ]) );

        set("indoors", "sharen");
        set("no_death_penalty",1);
          set("item_desc", ([
                "蜡像": @TEXT
一个神采奕奕，栩栩如生的蜡像，脚边写着「功授有心人」。
很显然是一位武林前辈摆在这里接受人参拜（knee）的遗像。
TEXT
        ]) ); 
        set("coor/y",-430);
        set("coor/z",0);
        set("coor/x",-15);
        setup();
        create_door("east", "青铜门", "west", DOOR_CLOSED); 
         //replace_program(ROOM);
} 

void init() {
    add_action("do_knee", "knee");
    add_action("do_standup", "standup");
	add_action("do_push", "push");
	//增加random机关
} 

int do_standup(){
    object me;
    me = this_player();
    if(me->is_busy()) {
        return notify_fail("你正在忙！\n");
    }
    if(me->is_fight()) {
        return 0;
    }
    if(!me->query_temp("state/knee")) {
        return 0;
    }
    me->delete_temp("state/knee");
    message_vision("$N站起身来。\n", me);
    return 1;
} 

int do_knee(string arg) {
        object me, who;
        int dayTime, j; 
        me = this_player();
        if(me->is_busy()) {
                return notify_fail("你正在忙!\n");
        }
        if(me->is_fight()) {
                return notify_fail("战斗中跪拜，想死吗？\n");
        } 
    if(me->query_temp("state/knee")) {
        return notify_fail("你已经在跪拜了。\n");
    }
    message_vision("$N跪了下来，突然坐垫下有个石刻的八卦图，似乎可以打开（Push 1-8）。\n", me);
    me->set_temp("state/knee", 1);

        return 1;
}

int do_push(string arg)
{
        object me;
		string *num = ({"1","2","3","4","5","6","7","8"}); 
        int i;
        i = random(7);
        me = this_player();
		if( !me->query_temp("state/knee") )
            return notify_fail("你要打开什么？\n");

		if( arg=="1" || arg =="2" || arg =="3" || arg =="4" || arg =="5" || arg =="6" || arg =="7" || arg =="8") {
			if( arg == num[i] ) {
			message_vision("只听得卡卡两声，坐垫忽然一沉，$N咕咚地往下掉了下去。\n\n\n", me);
			me->move("/d/sharen/andao1");
			me->delete_temp("state/knee");
			/*触发机关判断 */
			return 1;
			}
			else {  

             message_vision("$N搬动机关。。。突然不知从哪儿射出一跟铁针，$N被打了个正着！\n", me);
             me->receive_damage("qi",500);
			 me->start_busy(1);
             return 1;
			}
		}
		else {
            write("你要打开什么？\n");
            return 1;
		}

           return 1;       
 }      

int valid_leave(object who,string dir) {
        if(who->query_temp("state/knee")) {
                return notify_fail("你正跪着呢，不能离开！！\n");
        }
        return 1;
}      