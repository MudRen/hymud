 // SILENCER@FY4 ALL RIGHTS RESERVED
inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "����");
        set("long", @LONG
ת��һ���ʯ����ǰ��Ȼһ����ˮ����������������ͷ�����ش��£�ѹ����
����������������������������һ�������Ҷ���Ȼ�Ǵ��������ٵ��жΣ��������
ʮ���ɸߣ������Ǳ��̵�̶ˮ����������ʯ����һ��С������ͨȥ��
LONG
        );
        set("exits", ([ 
                "northdown" : __DIR__"exit3",
                "eastup" : __DIR__"oneway1",
                        ]));
        set("item_desc", ([
                "̶ˮ": "̶ˮ���Ҳ������ȥ���л��ᡣ\n",
        ]) ); 
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
void init()
{
        add_action("do_dive", "dive");
        add_action("do_dive", "jump");
        add_action("do_dive", "jumpdown");
        add_action("do_dive", "jumpto");
        add_action("do_dive", "charge");
        add_action("do_climb", "climb");
} 
int do_dive(string arg)
{
        object room;
        object me;
        me = this_player();
        call_out("jump_down",6,me);
        me->start_busy(3);
        message_vision(YEL"$N�������˿�����һ���ۣ����ٲ�����ȥ��\n"NOR,me);
        tell_object(me,YEL"��Խ׹Խ�죮���������ƺ�������һ���ҽУ�����ë���Ȼ��\n"NOR);
        tell_object(me,YEL"��ͨһ������һͷ������̶ˮ�С�\n"NOR);
        return 1;
} 
int jump_down(object me)        {
        object room;
        if(!objectp(me)) return 1;
        if (me->is_ghost()) return 1;
        room=find_object("/d/eren/waterfall");
        if(!objectp(room)) 
                room = load_object("/d/eren/waterfall"); 
        me->move(room);
        message_vision(HIG"$Nʪ���ܵش�ˮ�︡���������ϰ���\n"NOR,me);
        return 1;
}  
int do_climb(string arg)
{
        object obj;
        object me, room;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "ɽ" || arg == "mountain" || arg == "down")
        {
                write("����ط�̫�գ����������ȥ��\n");
                return 1;
        }
        else
        {
                write("�㲻������ô����");
                return 1;
        }
}  
int valid_leave(object who, string dir){
        int i, room_full;
        object *inv, room;
   
        if (!userp(who))        return 1;
        if(dir == "eastup"){
                room=find_object(__DIR__"oneway1");
                if(!objectp(room)) 
                room = load_object(__DIR__"oneway1"); 
                inv = all_inventory(room);
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i])) room_full=1;
                }
                if (room_full) {
                        tell_object(who,"ǰ����·��խ��ֻ����һ�����ߡ�\n");
                        return notify_fail("");
                }       
        }       
        return 1;
}       
