 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short","�¹۷�");
  set("long",@LONG
���ƴ�÷嶥�Ͻ���һ��Сͤ�ӣ�ͤ����С�����������ɽ֮�ϣ�Ҳ�ǲ��ף�
�չ۷�ĺ��գ��¹۷�Ľ��¶��Ǽ��ÿ��ľ��£�ÿ�����֮ҹ���¸������ϣ���
��ʤ�գ���ǡ�������ˬ֮ʱ���������£��˷���裬��֮���£�ʵ���޿ɱ��⡣
�¹۷�����ǰ�У�������������Ӣ������֮�ء������޹�ɽׯ����
LONG
  );
    set("exits",([
            "down" : __DIR__"shanfeng",
        "northup" : __DIR__"yushijie3",
    ]));
    
        set("objects", ([
                __DIR__"npc/mantrainer" : 1,
        ]) );
    set("outdoors", "taishanfy");
        set("coor/x",310);
        set("coor/y",2390);
    set("coor/z",125);
        setup();
        replace_program(ROOM);

} 
void init(){
    int dayTime;
    mixed *local; 
    //local = NATURE_D->get_current_time();
    dayTime = random(2000);

    if (random(10) > 3 && (dayTime < 210 || dayTime > 1260)) {
//if(1==1) {
//      write("call_ing\n");
        call_out("falling_star", random(60), this_player());
    }     
} 
void falling_star(object me) {
    int i, age;
    
    if(environment(me) != this_object() ) {
        return;
    }
    if(me->is_fighting()) {
        return;
    }
    message("vision", HIW"\n    һ����ɫ�ǹ⻮������ɫ��ҹ�գ�û�����ɽ�͵ĺ��档 \n"NOR, me);
    message("vision", HIC"ֻ������������һƬ��\n"NOR, me);
    age = me->query("age");
    if (age >= 18 && age <= 28 && !me->query("����A/̩ɽ_����")) {
        tell_object(me,HIG"\n������û�����ɽ��ǰ����ĬĬ�����������˸�Ը��\n"NOR);
        me->set("����A/̩ɽ_����", 1);       
    }   
}      
