 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����կ");
        set("long", @LONG
��ط�������կ���������ֺ�����Ⱥɽ��������崣��������������һֻҰ
�ޣ����Ŵ������ڵ������˶��ɡ�ס��������ˣ�Ҳ������һȺҰ�ޡ�˭Ҳ��Ը��
��Ұ������ȥ��������ط��ǵ����ٿ��ü�İ���ˣ��������Ѽ���������
LONG
        );
        set("exits", ([ 
                "northwest" : __DIR__"forest3",
        ]));
        set("objects", ([
                __DIR__"npc/baimian":   1,
                __DIR__"npc/tulaohu":   1,
                __DIR__"npc/oneeye":    1,
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1000);
        set("coor/y",-30);
        set("coor/z",0);
        setup();
//      NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
} 
/*
void reset() {
        object badguy,*inv,room=this_object();
        int count,i;
        
        ::reset();
        
        inv=all_inventory();
        for (i=0;i<sizeof(inv);i++) {
                if (inv[i]->name()=="ɽկ���")
                        count++;
        }
        if (count<4) {
                badguy=new(__DIR__"npc/bandit");
           badguy->set("attitude", "friendly");
                badguy->move(room);
                badguy->command("say ����,С��׼�����ˡ�");
        }
}
        
*/ 
/* 
void midnight_event() {
        object badguy;
        object room = this_object();
        int i, bandit_no = 2 + random(5);
        
        if(!random(10)) {
                for(i=0; i<bandit_no; i++) {
                        if(objectp(badguy = new("/obj/npc/bandit"))) {
                                badguy->setup_bandit("ɽ������", "/clone/misc/cloth", "/obj/weapon/blade_guitou", "fy");
                                badguy->move(room);
                                badguy->command("chat �º�ɱ�ˣ���߷Ż�");
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
                if(ob_list[i]->query("area_mark") == "fy") {
                        if(environment(ob_list[i])) {
                                message_vision("$N�е�������Ҳ��������\n",ob_list[i]);
                        }
                        destruct(ob_list[i]);
                }
        }
        NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
}
*/      
