 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "é��");
        set("long", @LONG
����µĹ��ڣ���Ȼ�Ǿ������ĵ���ƣ�ÿһ��ط�����û���˷ѣ�
�����������������Ƿ���֮����һ�������Ƶļ�ɽʯ���и��׿ӣ�����
���Ÿ����ӡ� 
LONG
        );
        set("exits", ([ 
       "south" : __DIR__"corridor",
        ]));
        set("item_desc", ([
                "��ɽʯ": "����֮������Ҫ�и����˶�Ŀ�Ķ�����������\n",
                "rock": "����֮������Ҫ�и����˶�Ŀ�Ķ�����������\n",
                "����": "�׿��ϵĸ���(lid)���ƺ����Դ򿪣�open����\n",
                "lid": "�׿��ϵĸ���(lid)���ƺ����Դ򿪣�open����\n",
                "gaizi": "�׿��ϵĸ���(lid)���ƺ����Դ򿪣�open����\n",
                "��": "һ������ͨ�Ķ׿ӣ������и�����(lid)���ƺ����Դ򿪣�open����\n",
                "ken": "һ������ͨ�Ķ׿ӣ������и�����(lid)���ƺ����Դ򿪣�open����\n",
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        set("lid_open",0);
        setup();
} 
void init()
{
        add_action("do_open", "open");
        add_action("do_climb", "climb");
} 
int do_open(string arg)
{
        object me;
        me = this_player();
        if (arg=="lid" || arg=="����") {
                message_vision(YEL"$N�Ѹ�������һ����Ϥ����ζ���������\n"NOR,me);
           message_vision(YEL"�����Ǹ���ӣ���Ե�ϻ�ճ��Щ�ư�֮�\n"NOR,me);
                set("lid_open",1);
        }       
        return 1;
}  
int do_climb(string arg)
{
        object obj;
        object me, room;
        
        me=this_player();
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "��" || arg == "ken" || arg == "down")       {
                if (!query("lid_open"))
                        return notify_fail("���Ӹ�����ô����\n");
                call_out("climb_down",6,me);
                me->start_busy(3);
                message_vision("$Nһè������˶׿ӣ���֫���õ�������ȥ��\n",me);
                return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n��");
                return 1;
        }
} 
int climb_down(object me)       {
        object room;
        if(!objectp(me)) return 1;
        if (me->is_ghost()) return 1;
        room = find_object(__DIR__"hole");
        if(!objectp(room)) 
                room = load_object(__DIR__"hole");  
        message_vision(YEL"��ӱ���һ����ͨ����£���û�¼��ߣ��Ա߾�������С����\n"NOR,me);
        message_vision(YEL"$N����һ��������С���������Ǹ�СС�Ķ���\n\n"NOR,me);
        message("vision",YEL"С�����������������������\n"NOR,room);
        me->move(room);
        return 1;
} 
void reset()
{
        ::reset();
        set("lid_open",0);
        
}    
