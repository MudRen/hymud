// sanqingdian.c �����
// by Xiang
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
���������������������䵱�ɻ�͵ĵص㡣����Ԫʼ����̫�ϵ�
���������Ͼ��������㰸���������ơ���ǽ���ż���̫ʦ�Σ����Ϸ��ż�
�����š��������������ȣ�����������Ĺ㳡���ϱ��Ǻ�Ժ��
LONG );
        set("valid_startroom", 1);
        set("exits", ([
                "north" : __DIR__"guangchang",
                "south" : __DIR__"houyuan",
                "east"  : __DIR__"donglang1",
                "west"  : __DIR__"xilang",
        ]));
        set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi$#");
        set("objects", ([
                CLASS_D("wudang") + "/guxu" : 1,
                CLASS_D("wudang") + "/song" : 1,
                "/d/biwu/champion_wd" :1,
    "quest/menpai/wudang/shi" : 1,                      
        ]));
//        set("no_clean_up", 0);
        setup();
        "/clone/board/wudang_b"->foo();
}

void init()
{
        object me;
        mapping skill_status;
        string *sname;
        int i, level;
        float exper;

        me = this_player();

        exper = to_float(me->query("combat_exp"));

        if ( !(skill_status = me->query_skills()) ) return;
        sname  = keys(skill_status);

        for(i=0; i<sizeof(skill_status); i++)
        {
                level = skill_status[sname[i]];
                if( pow(to_float(level), 3.0) / 10.0 > exper
                && exper > 100.0
                && sname[i] != "buddhism"
                && sname[i] != "literate"
                && sname[i] != "taoism" )
                {
                        level = ceil( pow( exper*10.0, 0.333333) );
                        me->set_skill(sname[i], level);
                }
        }
        add_action("do_turn", "turn");
}
int do_turn(string arg){
        object me, guard, nroom;    
        me = this_player();
        if(!arg || (arg != "handle" && arg != "����")) {
                tell_object(me,"��Ҫתʲô��\n");
                return 1;
        }
        message_vision(HIY "$N�������ϰ���һ�£����º�Ȼ�ѿ���һ���󶴣�\n$N�����һ����������ȥ��\n"NOR, this_player());
        nroom = find_object("/d/ghost/dijiao");
        if(!objectp(nroom)) nroom=load_object("/d/ghost/dijiao");
   me->move(nroom);
        message_vision(HIY "\n$N�߽��������ĺ��š�\n"NOR, me);
        return 1;
}  
