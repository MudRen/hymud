#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "����");
        set("long", @LONG
ʯ���Ᾱ��һ�������ε�ʯ�ң���Ҳû�б���Ż���Ƕ��ʯǽ�е�ʮ
��յͭ��ȼ��ͨ����ʯ��������һ�ںܴ��ʯ�ף��������ʯ����Щʯ
��ȫ������ƻ�������ú�κ������ģ�������Ҷ������˲���С��
�Գ�һ�飬ÿһ������̬����ͬ��ÿһ��ʯ�񶼵�û�����֣��˺���¶��
ʹ���̲�ס������һ���Ա���α��
LONG
        );
        set("exits", ([ 
            "south" : __DIR__"mouseroom3",
                ]));
        set("item_desc", ([
                "ʯ��": "�ƻ��������ſ�ڵ��ϣ�κ������̤�����ǵı������ֻ��ٸ������ںȾơ�\n",
                "statue": "�ƻ��������ſ�ڵ��ϣ�κ������̤�����ǵı������ֻ��ٸ������ںȾơ�\n",
                "shixiang": "�ƻ��������ſ�ڵ��ϣ�κ������̤�����ǵı������ֻ��ٸ������ںȾơ�\n",
        ]) );
        
        set("objects", ([
                __DIR__"npc/wuya" : 1,
                __DIR__"npc/mice5" : 1,
                __DIR__"npc/mice6" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
} 
void init()
{
        add_action("do_touch", "touch"); 
}  
int closepath()
{
        if( !query("exits/up") ) return 1;
        message("vision","�����ϵ�С����������Ϣ�ĺ����ˡ�\n",this_object());
             delete("exits/up");
        return 1;
}  
int do_touch(string arg)
{
        object guard;
        if(!arg || (arg != "ʯ��" && arg != "statue" && arg!="shixiang")) {
                return 0;
        }
        if (guard=present("wei wuya",this_object()))
        if (guard) {
                message("vision","κ����������һ�ۡ�\n",this_object());
                return 1;
                }
        if (this_player()->is_busy())
               {
                tell_object(this_player(),"��������æ��\n");
                return 1;
                }       
        add("num",1);
        this_player()->start_busy(1);
        switch (query("num"))   {
                case 1: message_vision(CYN"�ƻ�������ʯ����˻Σ��ƺ��ڰ����ؿ�����\n"NOR,this_player());
                        break;
                case 2: message_vision(CYN"�ƻ�����ʯ���ͷ�������ڵ��Ͽ��˼��¡�\n"NOR,this_player());
                        break;
                case 3: message_vision(CYN"�ƻ�����ʯ���ͷ����֨֨��̧���������˼����ǡ�\n"NOR,this_player());
                        break;
                case 4: message_vision(CYN"�ƻ�����ʯ���������һָ����ྲ꣢һ�����������ѳ���һ�����š�\n"NOR,this_player());
                        if (!query("exits/up")) {
                                set("exits/up",__DIR__"tunnel1");
                                call_out("closepath",10);
                                }
                        set("num",0);
                        break;
                default: break;
        }               
        return 1;
} 
void reset()
{
::reset();
delete("num");
}  
