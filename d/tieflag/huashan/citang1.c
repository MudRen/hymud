#include <ansi.h>
inherit ROOM;
string tree();
string citang();
void create()
{
        set("short", "����ǰԺ");
        set("long", @LONG
�ƹ���ǽ��һ�����ã����õ�Ժ���һ���Ű������ڵأ���Ŀ��ǽ�ϱڡ�Ժ
��һ�ù������ƺ��кܶ���ѻ�ĳ�Ѩ����ʱ������ѻ�����ɡ��Ľ������˷��ꡣ�Ĳ�
ûϥ���ڷ��з�����ɪ��������Ժ����һ�����õ����á�
LONG
        );
    set("exits", ([ 
                "west" : __DIR__"hpath2",
                "east" : __DIR__"citang2",
        ]));
        set("objects", ([
                __DIR__"obj/huangcao" : 1,
                __DIR__"obj/door" : 1,
        ]) );   
        set("item_desc", ([
                "tree" : (: tree :),
                "����" : (: tree :),
                "��" : (: tree :),
                "����" : (: citang :),
                "citang" : (: citang :),
        ]) );
        set("have_spear", 1);
    set("outdoors", "huashan");
    set("coor/x",-572);
    set("coor/y",-25);
    set("coor/z",30); 
        setup();
} 
string citang(){
        object me;
        string weather;
        int i;
        i = random(20);
   me = this_player();
        if(i == 3){
        weather = "���";
        if (random(5)==1)  weather = "���";
         if (random(5)==1)  weather = "ѩ";	
         if (random(5)==1)  weather = "��ѩ";	
if (random(6)==1)  weather = "��";	
        if (random(6)==1)  weather = "����";	
        if((weather == "��" || weather == "����") && query("have_spear")) {
                        tell_object(me, "��ǽһ�ǵ����ӱ���ˮ�ݵ���Щ���䣨������� ������򣩡�\n");
                        add_action("do_search", "search");
                        return "";
                } 
                if (!query("have_spear") && !present("corner", this_object())) {
                        tell_object(me, "��ǽһ�ǵ������Ѿ��ƿ��������ƺ����������˶�����\n");
                } else {
                        tell_object(me, "��ǽһ�ǵ����ӱ���ˮ�ݵ���Щ���䡣\n");
                }
                
        } else {
                tell_object(me, "һ���ƾɵļ�춵��������á�\n");
        }
        return "";
} 
int do_search(string arg){
        object me, corner, spear;
        me = this_player();
        if(!arg || (arg != "corner" && arg != "����")){
                return notify_fail("��Ҫ��Ѱ���\n");
        }
        message_vision("$N�����������ӣ���ž����һ����һƬ��ľ����������\n", me); 
        tell_object(me, "�������ƺ���һ��������Ķ�����\n"); 
        corner = new(__DIR__"obj/corner");
        spear = new(__DIR__"obj/zhangspear");
        if(objectp(corner)){
                corner->move(this_object());
        }
        if(objectp(spear)){
                spear->move(corner);
        }
        set("have_spear", 0);
        return 1;
} 
string tree(){
        object me;
   int i, j;
        me = this_player();
        i = random(4);
        message("vision", me->name() + "��ͷ�����Ͽ��˿���\n", environment(me), me);
        if(i == 4) {
                tell_object(me, "��ͺͺ���������м����޴�����ѡ�\n");
        } else {
                tell_object(me, "֦Ҷï�ܣ�����ѿ�������Ķ�����\n");
                j = me->query("kar");
                if(random(j) < 2 && i != 3 && random(10)==0){
                        message_vision(YEL"��Ȼ��һ��������¸պ��ҵ�$N��ͷ�ϡ�\n"NOR, me);
me->set("����B/��ɽ_���", 1+random(10));
                }
        }               
        return "";
}      
