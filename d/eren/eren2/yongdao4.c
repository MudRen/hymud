 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
������ʮ���ᣬ����һת����ڰ���խ�Ķ�Ѩ������Ȼ����������ʯ�����ԣ�
�����Ű���㾧Ө�⻬��ʯ�飬���������еƹ�͸��ȴ�Ʋ�������Ƕ������ġ�
û��������������ɱ����
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"yongdao5",
                "westup" : __DIR__"yongdao3",
        ]));
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
int valid_leave(object me,string dir)
{
        object alert_room;
                
        if(userp(me) && dir == "eastdown")      {
                alert_room = find_object(__DIR__"yongdao3a");
                if(!objectp(alert_room)) 
                        alert_room = load_object(__DIR__"yongdao3a");           
                if (alert_room->query("trap")) {
                        message_vision(HIR"���ߺ����ƿ�֮������֦��ʸ����ڵĽ�������$N������\n"NOR, this_player());
                        if (random(me->query_skill("perception",1))>100 || random(me->query_skill("dodge",1)>100))
                                message_vision(YEL"$N�����������������ڼ䲻�ݷ�֮�̶㿪�˰�����\n"NOR,me);
                        else {
                                message_vision(YEL"$N���������������˸����š�\n"NOR,me);
                                me->receive_wound("jing",me->query("eff_jing")/3);
                                me->receive_wound("qi",me->query("eff_qi")/3);
                                me->receive_wound("jing",me->query("eff_jing")/3);
                        }                                       
                }       
   }
        return 1;
}    
