 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "�ķϵ�����");
        set("long", @LONG
����������˻ҳ���һЩ��λ���ҵض�����̨�ϣ���ֻ��̨�������������̨
�ϡ�������տյģ������������������������Ǻ���ᣲ��������ƺ��½�����
������������ӡ�кܶ����ҵĽ�ӡ�� 
LONG
        );
    set("exits", ([ 
                "west" : __DIR__"citang1",
        ])); 
        set("item_desc", ([
                "ᣲ�" : "�������ĺ�ɫᣲ��ĸ������������������������գ��㲻�����ƿ�����������ʲô��
�����������������\n",      
                "curtain" : "�������ĺ�ɫᣲ��ĸ�������������������������,�㲻�����ƿ�����������ʲô��
�����������������\n",
        ]) );  
        set("objects", ([
                __DIR__"obj/shentai" : 1, 
                "/kungfu/class/hu/yuzhenzi" : 1, 
        ]));
    set("indoors", "huashan");
    set("coor/x",-570);
    set("coor/y",-25);
    set("coor/z",30);
        setup();
} 
void init(){
        add_action("do_open", "open");
} 
int do_open(string arg)
{
        object player,kumei;
        player = this_player();
        if(arg != "ᣲ�" && arg != "curtain") {
                return 0;
        }
        if ( player->query("marks/�ҳ�") == 1 
                   || player->query("marks/�ҳ�") == -1)
        {
                message_vision("$N�ƿ�ᣲ��������������һ����ɫ��Ӱ�ӹ����ֺ���ֻ�ǻþ���\n",player);
                return 1;
        }
        kumei = new(__DIR__"npc/kumei.c");
        kumei->move(this_object());
        message_vision("$N�����ƿ�ᣲ��� \n\n\n",player);
        message_vision(HIB"��Ȼᣲ�����һ�£�$N��ǰ����Ȱ����һ��$n�� \n\n\n"NOR,player,kumei);
        kumei->apprentice_me(player);
        return 1;
}  
