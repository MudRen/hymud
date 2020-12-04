 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���˸�");
        set("long", @LONG
һ���ܷ��ʯ�ң���������Ѫ�ȵ�ζ���������ݷ��Ѿ����̣���
�˷ǳ�ѹ�֡����ڿ�ǽ�ĵط�������������Щ�Ѿ����ơ�ֻ�е���
һ��������һ��ʯ���ϣ�Ŀ��ת���ؿ����㣬�������е��ĻŻš���
����Ȼû������Ż�µ�ɱ�������㻹���뾡���뿪��
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
                "����": @TEXT
һ��������ȣ��������������񣬽ű�д�š����������ˡ���
����Ȼ��һλ����ǰ��������������˲ΰݣ�knee��������
TEXT
        ]) ); 
        set("coor/y",-430);
        set("coor/z",0);
        set("coor/x",-15);
        setup();
        create_door("east", "��ͭ��", "west", DOOR_CLOSED); 
         //replace_program(ROOM);
} 

void init() {
    add_action("do_knee", "knee");
    add_action("do_standup", "standup");
	add_action("do_push", "push");
	//����random����
} 

int do_standup(){
    object me;
    me = this_player();
    if(me->is_busy()) {
        return notify_fail("������æ��\n");
    }
    if(me->is_fight()) {
        return 0;
    }
    if(!me->query_temp("state/knee")) {
        return 0;
    }
    me->delete_temp("state/knee");
    message_vision("$Nվ��������\n", me);
    return 1;
} 

int do_knee(string arg) {
        object me, who;
        int dayTime, j; 
        me = this_player();
        if(me->is_busy()) {
                return notify_fail("������æ!\n");
        }
        if(me->is_fight()) {
                return notify_fail("ս���й�ݣ�������\n");
        } 
    if(me->query_temp("state/knee")) {
        return notify_fail("���Ѿ��ڹ���ˡ�\n");
    }
    message_vision("$N����������ͻȻ�������и�ʯ�̵İ���ͼ���ƺ����Դ򿪣�Push 1-8����\n", me);
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
            return notify_fail("��Ҫ��ʲô��\n");

		if( arg=="1" || arg =="2" || arg =="3" || arg =="4" || arg =="5" || arg =="6" || arg =="7" || arg =="8") {
			if( arg == num[i] ) {
			message_vision("ֻ���ÿ��������������Ȼһ����$N���˵����µ�����ȥ��\n\n\n", me);
			me->move("/d/sharen/andao1");
			me->delete_temp("state/knee");
			/*���������ж� */
			return 1;
			}
			else {  

             message_vision("$N�ᶯ���ء�����ͻȻ��֪���Ķ����һ�����룬$N�����˸����ţ�\n", me);
             me->receive_damage("qi",500);
			 me->start_busy(1);
             return 1;
			}
		}
		else {
            write("��Ҫ��ʲô��\n");
            return 1;
		}

           return 1;       
 }      

int valid_leave(object who,string dir) {
        if(who->query_temp("state/knee")) {
                return notify_fail("���������أ������뿪����\n");
        }
        return 1;
}      