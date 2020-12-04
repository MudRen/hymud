 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short","�չ۷�");
  set("long",@LONG
�˴��ǹ����ճ�������ѵط����������£�������ȣ�����ϰϰ������Ʈ����
����Ⱥɽ�������۲����Ļ��ÿ���峿��һ�ֺ����Զ�����ɣ���Ϻ�ճ�������
���Ƶͣ����ڽ��£�����һ���ֿ�������֮�ƣ�����Ӣ�۵��ˣ��޲�Ϊ֮����ӿ����
LONG
  );
    set("exits",([
            "south" : __DIR__"zhanlu",
            	"east" : "/d/taishan/riguan",
    ])); 
    set("outdoors", "taishanfy");
        set("coor/x",340);
        set("coor/y",2400);
        set("coor/z",120);
        setup();
}  
void init(){
    int dayTime;
    mixed *local; 
    //local = NATURE_D->get_current_time();
    dayTime = random(2000);
    if (dayTime > 240 && dayTime < 290) {
        this_player()->set_temp("watch_sunrise", 1);
        remove_call_out("sun_rise");
        call_out("sun_rise", 300 - dayTime, random(2), 0);
    }
} 
void sun_rise(int sunrise, int sunrise_stage) {
    object *inv, *watchers;
    int i, j; 
    remove_call_out("sun_rise");
        inv = all_inventory();
        watchers = filter_array(inv, (: interactive($1) && $1->query_temp("watch_sunrise") :));
    if(sunrise_stage == 0 && random(10) > 3) {
        message("vision", HIW"����һƬ����ãã������ʪ���ƺ�����š��ˮ������ʲô�����������\n"NOR, watchers);
    } else if(sunrise == 0) {
        switch(sunrise_stage) {
            case 0:
                message("vision", RED"\nһ���ɫ�Ĺ�â�ո�̽���Һ�ɫ�ĵ�ƽ�ߣ���ʱ�����ϼ����������ա�\n"NOR, watchers);
                message("vision", RED"ɽ�͵Ķ�������Ⱦ�ɺ�ɫ�� \n\n"NOR, watchers);
                        call_out("sun_rise", 5, 0, 1);
                break;
            case 1:
                message("vision", HIR"\n�ۺ�ɫ��̫�������Ĵӵ�ƽ��������������غ�Ȼ֮������������\n"NOR, watchers);
                message("vision", HIR"ɽ��ĳ���ֹס�˽��������ڹ�ӭ�µ�һ��ĵ�����\n"NOR, watchers);
                call_out("sun_rise", 5, 0, 2);
                break;
            case 2:
                message("vision", HIR"\nһ�ֺ���ӳ����ߵĲ�ϼ�����شӶ�������\n"NOR, this_object(), watchers);
                message("vision", HIY"\n̫������Ծ���˵�ƽ�ߣ�������ﶼ��������һ�㵭���Ľ�ɫ�� \n"NOR, watchers);
                j = random(20);
                if (j == 3) {
                    message("vision", HIY"\nɽ�µķ�Ҷ��Ҳ�����˵����Ľ�ɫ�����ķ�Ҷ��ϼ���������������ʵ���ɫ��\n"NOR, watchers);
                    message("vision", HIY"����ʧ������ʵ������\n"NOR, watchers);
                    for(i=0; i<sizeof(watchers); i++) {
                        if (!watchers[i]->query("����B/̩ɽ_�ճ�")) {
                            watchers[i]->set("����B/̩ɽ_�ճ�",1+random(10));
                        }
                    }
                }
                break;
                default:
                        return notify_fail("something wrong\n");
        }
    } else {
        switch(sunrise_stage) {
            case 0:
                message("vision", RED"\n�����Ʋ����������ĺ�������Ľ��¡�����Զ�����������ĵط���������һ˿���͸�֣�\n"NOR, watchers);
                message("vision", RED"�����һƬ������ \n"NOR, watchers);
                call_out("sun_rise", 5, 1, 1);
                break;
            case 1:
                message("vision", HIR"\nzת�ۼ���߳�����һ������ɫ��ϼ�⣬ϼ�ⲻͣ�ر任����ɫ������ɫ��ǳ�졢�ۺ��ɫ�ʡ�\n"NOR, watchers);
                message("vision", HIR"̫��Ҳ¶���˺�ͮͮ��С�����������ƻ�ȴû�й�����\n"NOR, watchers);
                call_out("sun_rise", 5, 1, 2);
                break;
            case 2:
                message("vision", HIR"\nһ�ֺ���ӳ����ߵĲ�ϼ�����شӶ�������\n"NOR, this_object(), watchers);
                message("vision", HIR"\n̫���ƺ������غ��Ƶ�һ��һ����������Ŭ������������������ڳ�������ϼ���������Ʋ㣬\n"NOR, watchers);
                message("vision", HIR"��ɫ��÷ǳ��ɰ���һɲ������ɰ��ĺ�ɫԲ��ͻȻ����ҫ�۵Ĺ�����\n"NOR, watchers);
                j = random(20);
                if (j == 4) {
                    message("vision", HIR"\n���İ��Ʊ�Ⱦ������ɫ��ʣ���ʲ�ͣ�������任��������ĳ����������ŵĹ�������С�\n"NOR, watchers);
                    for(i=0; i<sizeof(watchers); i++) {
                        if (!watchers[i]->query("����B/̩ɽ_�ճ�")) {
                            watchers[i]->set("����B/̩ɽ_�ճ�",1+random(10));
                        }
                    }
                }
                break;
                default:
                        return notify_fail("something wrong\n");
        }
    }
}
int valid_leave(object me, string dir){
    me->set_temp("watch_sunrise", 0);
    return 1;
}  
