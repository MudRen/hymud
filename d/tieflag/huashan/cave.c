#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "ëŮ��");
        set("long", @LONG
ëŮ����˵��ëŮ����������ëŮΪ��ʼ�ʹ�Ů�������ɽѳ��֮�֣���
�����ع��۷���Я���뻪ɽ����ҵ����ʿָ�㣬��ʳ�ɰ��ѣ�������Ȫˮ����ʹ
������ë���в���ɡ���˵ɽ����ʦ���������˿�������������ҹ���˾�ʱ����
Ȼ��������ëŮ���������ߵ�������
LONG
        );
    set("exits", ([ 
                "northdown" : __DIR__"shaluo",
        ]));
        set("listen", 0);
        set("music", 0);
    set("indoors", "huashan");
    set("coor/x",-575);
    set("coor/y",-45);
    set("coor/z",50);
        setup();
} 
void init(){
    mixed *local;
    int dayTime;
    if(random(20)==0){
                //local = NATURE_D->get_current_time();
                //dayTime = local[5];
        //if(dayTime > 1200 && NATURE_D->get_weather() == "��") {
                call_out("make_sound", 120, this_player());
        //}
    }
        add_action("do_listen", "listen");
} 
int make_sound(object me){
        if(objectp(me) && environment(me) == this_object()){
                message_vision(CYN"һ�����Ƶ�������֪�Ӻδ����������������������������
���ҳ���������Դ��\n"NOR, me);  
                call_out("music_gone", 30);
           set("listen", 1);
        }
} 
void music_gone(){
        set("listen", 0);
} 
int do_listen(){
        object me;
        me = this_player();
        if(query("listen")){
                message_vision("\n��Զ��������ҹɫ���������ߣ���ѭ��������ϸѰ�ң����������ƺ��Ӷ���������\n",
                                me); 
                me->apply_condition("music", random(10));
                set("listen", 0);
        }       
        return 1;
} 
