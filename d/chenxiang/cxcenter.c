 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM; 
void midnight_event();
void sunrise_event(); 
void create() {
        set("short", "�ϳǹ㳡");
        set("long", @LONG
�����ǵ������������ģ��㳡�ı�����һ��С�������������Ա���
һ�����ʯ���͵���������ϰ���С��ͷ�����ϲ�������Ϊ����֮�磬��
���Ѿ���Ϊ����ǵ�ũ���г��ˡ�
LONG);
        set("exits", ([
                        "north" : __DIR__"cx4",
                        "south" : __DIR__"cxs1",
                        "east" : __DIR__"cxe1",
                        "west" : __DIR__"nanbank",
                        ]));
        set("objects", ([
                        __DIR__"npc/fishseller": 1,
                        __DIR__"npc/fishbuyer": 1,
                        //"/p/residence/npc/xiaolang" : 1,
                        ]) );
        set("outdoors", "chenxiang");
        set("coor/x",-500);
        set("coor/y",-500);
        set("coor/z",0);
        setup();
        NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
} 
void midnight_event() {
        object badguy;
        object room = this_object();
        int i, bandit_no = 3 + random(7);
        
        if(!random(20)) {
                for(i=0; i<bandit_no; i++) {
                        if(objectp(badguy = new("/obj/npc/bandit"))) {
                                badguy->setup_bandit("��������", "/clone/misc/cloth", "/obj/weapon/blade_guitou", "cx");
                                badguy->move(room);
                           badguy->ccommand("chat �º�ɱ�ˣ���߷Ż�");
                        }
                }
                NATURE_D->add_day_event(3, 1, this_object(), (: sunrise_event :));
        } else {
                NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
        }
} 
void sunrise_event() {
        object *ob_list;
        int i;
        
        ob_list = children("/obj/npc/bandit");
        for(i=0; i<sizeof(ob_list); i++) {
                if(ob_list[i]->query("area_mark") == "cx") {
                        if(environment(ob_list[i])) {
                                message_vision("$N�е�������Ҳ��������\n",ob_list[i]);
                        }
                        destruct(ob_list[i]);
                }
        }
        NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
}  
