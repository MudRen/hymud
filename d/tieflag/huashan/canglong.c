#include <ansi.h>
 inherit ROOM;
void fall(object me);
void create()
{
        set("short", "������");
        set("long", @LONG
���ε�ɽ���ʲԺ�ɫ��ʯ·��Լ���ף��������ߣ�������Ԩǧ�ߣ�ÿ��ɽ��
����������Ʈ��������������վ�ƶˣ����Ƴ˷��ȥ�����˲��ɵ������ҡ������
�쳣����ʫ���������������ϣ�ز�����ѷɡ�����һ�������������ɴ��� ѭ������
�У�ʼ���ݺ�ʩ�����꼰׹�ǣ�������紵�� ��
LONG
        );
    set("exits", ([
        "westdown" : __DIR__"qianchi", 
                "northup" : __DIR__"yuntai",
                "southup" : __DIR__"yunv",
            "eastdown" : __DIR__"xiaodao",
        ]));
        set("objects", ([
                __DIR__"npc/gao" : 1,
        ]));   
    set("outdoors", "huashanfy"); 
    set("coor/x",-577);
    set("coor/y",-90);
    set("coor/z",70);
        setup();
}
/*
void init()
{
        add_action("do_jump", "jump");
} 

int do_jump(string arg)
{
        object  me;
        int     cor;
        object  room; 
        if(!arg || arg != "down") 
        {
                write("��Ҫ�������\n");
                return 1;
        }
        me = this_player();
    cor = (int)me->query_cor();
        
        if(cor < 20) 
                message_vision(HIY"\n$N̽ͷ�������¿��˿��������е���£�\n"NOR, me);
        else {
                message_vision(HIY"\n$Nһҧ������������ɽ�£�����\n"NOR, me);
                message_vision(HIR"����ͨ��һ����$Nˤ���µף����ҵ���ʹ$N���˹�ȥ����\n"NOR,me);
                me->unconcious();
                room = find_object(__DIR__"yadi");
                if(!objectp(room)) room= load_object(__DIR__"yadi");
                me->move(room);
        }
        return 1;
} 
*/


void init(){
        int i;
        object me;
        string weather;
        
        me = this_player();
        weather = "���";
        if (random(5)==1)  weather = "���";
         if (random(5)==1)  weather = "ѩ";	
         if (random(5)==1)  weather = "��ѩ";	
if (random(6)==1)  weather = "��";	
        if (random(6)==1)  weather = "����";	
        if(weather == "���" && !random(200)) {
                message_vision("һ��紵����$N����һ�Σ�������һ�����У�$N����ɽ�¡�\n", me);
                fall(me);
        } else if(weather == "���" && !random(100)){
                message_vision("һ���紵����$N����һ�Σ�������һ�����У�$N����ɽ�¡�\n", me);
                fall(me);
   } else if((weather == "ѩ" || weather == "��ѩ") && !random(80)) {
                tell_object(me, "��ֻ���ý���һ�������Ӷ�Ȼ������һ�ߣ��㲻�ɵ÷�����һ�����С�\n");
                message("vision", "ֻ��һ�����У�$N������ɽ�롣\n", environment(me), me);
                fall(me);
        } else if(!random(600)) {
                message_vision("$Nһ����գ�������ɽ�롣\n", me);
                fall(me);
        }
} 
void fall(object me){
        object room;
        room = find_object(__DIR__"yadi");
        if(!objectp(room)){
                room = load_object(__DIR__"yadi");
        }
        me->move(room);
        message("vision", "ֻ��" + me->name() + "�ӿ���׹�䣬����ͨ��һ���䵽�˵��ϡ�\n", environment(me), me);
        if ( random(2) ) me->unconcious();
}      
