 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
����㾧Ө�⻬��ʯ���Ͼ�����һ�н�ӡ��ÿ�����ߣ�����һ�����������ó�
���Ż���ȥ�ģ�Ҳû����˹������롣ʯ��������һ����ƽ����ʵ���õ�����Ҳʮ
�ֲ����ס������˵Ľ�ӡ���ȵ��̵Ļ������
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"yongdao7",
                "westup" : __DIR__"yongdao4",
        ]));
        set("item_desc", ([
                "��ӡ": "��ӡ����ʯ��Լ�д����������ϣ������д˹�����\n",
                "footprint": "��ӡ����ʯ��Լ�д����������ϣ������д˹�����\n",
                "print": "��ӡ����ʯ��Լ�д����������ϣ������д˹�����\n",
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object me,string dir)
{
        object alert_room,trap_room;
                
        if(userp(me) && dir == "northdown")     {
                alert_room = find_object(__DIR__"yongdao3a");
                if(!objectp(alert_room))
                        alert_room = load_object(__DIR__"yongdao3a");
                if (alert_room->query("trap")) {
                        message_vision(HIR"ֻ�����������$N����ͻȻ������һ���󶴡�\n"NOR, me);
                        message_vision(YEL"$Nһ����������������ȥ��\n"NOR,me);
                        trap_room = find_object(__DIR__"trap1");
                        if(!objectp(trap_room))
                                trap_room = load_object(__DIR__"trap1");
           me->move(trap_room);
                me-> unconcious();
                return 1;
                }       
        }
        return 1;
}  
void init(){
        add_action("do_step", "step");
} 
int do_step(string arg){
        object me, guard;    
        me = this_player();
        if(!arg || (arg != "footprint" && arg != "��ӡ")) {
                return 0;
        }
        message_vision("$N���ŵ����ϵĽ�ӡ����˲ȣ���С��Զ�ˡ�\n",me);
        tell_object(me,"�������а���\n");
        return 1;
}     
