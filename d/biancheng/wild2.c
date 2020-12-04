 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��ԭ");
        set("long", @LONG
��������أ������������ɳ�����ޱ��޼ʵĻ�ԭ��������������û��·��
���������˳�����ˣ�̤��һ�����߿�ĳ��������ĵ��������ǳ��޻����ĺۼ���
ż���������۹�������ǰ����С�򡣵�·�����һ�Ÿߴ�İ����������ڱ��ư�
Ȼ������
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"wild1",
                //"northwest" : __DIR__"wild3",
                "southwest" : __DIR__"woods",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1080);
        set("coor/y",100);
        set("coor/z",0);
        setup();
} 
void reset() {
        object badguy,*inv,room,boss,village;
        int count,i;
        mixed current_time;
        string *boss_name=({"baimian langzhong","one eye","tu laohu",});
        string boss1;
        
        ::reset();
        
        room=this_object();
        current_time=NATURE_D->get_current_time();
        
        inv=all_inventory();
        for (i=0;i<sizeof(inv);i++) {
                if (inv[i]->query("group")=="longhuzhai")
           if (random(8)==0) {
                        if (inv[i]->query("id")=="bandit") {
                                inv[i]->command("say ����Ҳ��������");
                                message_vision("$Nһͷ����ϱߵ���������ʧ�ˡ�\n",inv[i]);
                                destruct (inv[i]);
                        } else {
                                room=find_object("/d/biancheng/village");
                                if (!room) destruct (inv[i]);
                                else {
                                        inv[i]->move(room);
                                        message_vision("$N��ɽկ�������˽�����\n",inv[i]);
                                }
                        }
                        
                } else count++;
        }
        
        if (random(8)==0) {
                if (!count) {
                        for (i=0;i<3;i++)       {
                                badguy=new(__DIR__"npc/bandit");
                                badguy->set("attitude", "friendly");
                                badguy->move(room);
                        }
                        message_vision("ֻ��ˢ����һ���죬·�Ե�������ܳ��˼������ˡ�\n",badguy);
                        badguy->command("say �ºڷ��ҹ��ɱ�˷Ż��졣");
                }       
                if (!present(boss_name[0],room) && !present(boss_name[1],room) && !present(boss_name[2],room))
                for (i=0;i<6;i++) {
                        boss1=boss_name[random(sizeof(boss_name))];
                        boss=find_living(boss1);
                        if (boss && !boss->is_fighting()) {
                                badguy=present("bandit",room);
                                message_vision(CYN"$N�ϻ̳Ͽֵ�˵������Ҳ���ˡ�\n"NOR,badguy);
                                message_vision(CYN"$Nһ��������һ��˵������ȥ��������������������������\n"NOR,boss);
                                boss->move(room);
                                boss->command("pat bandit");
                                return;
                        }
                }       
   }
        return;
}  
int valid_leave(object obj, string dir){
        int i;
        object *inv;
        if(dir == "east" || dir == "southwest"){
                if (obj->query_temp("wild2_pass") || obj->query("combat_exp")<1000000) return 1;
                inv = all_inventory(this_object());
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i]) ||!inv[i]->is_character()
                                ||inv[i]->is_corpse()) 
                                        continue;
                        if (inv[i]->query("group")=="longhuzhai") 
                                return notify_fail(inv[i]->name()+"˵������ɽ���ҿ������������ԣ�Ҫ���·����������·Ǯ����\n");
                }
        }       
        return 1;
}
