 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "ʯ��ջ��");
        set("long", @LONG
˵��·��ʵ��ֻ����ʯ��������߰ѿ��һ��ջ������ǿ������һ�����ߡ�ʯ
����������̦��һ��С�ľ��п��ܻ����ٲ��У��Һ�û������ʯ���Ͼ�����������
�԰��ա�ջ�����ٲ��ڲ��������죬�������⿴����һ˿�ۼ���
LONG
        );
        set("exits", ([ 
                "eastup" : __DIR__"oneway2",
                "westdown" : __DIR__"exit",
                        ]));
        set("outdoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object who, string dir){
        int i, room_full;
        object *inv, room;
        
        if (!userp(who))        return 1;
        if(dir == "eastup"){
        
        
        
        
        
        
                room=find_object(__DIR__"oneway2");
                if(!objectp(room)) 
                room = load_object(__DIR__"oneway2"); 
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
void init() {
        object ob;
        ob = this_player();
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
} 
void greeting(object ob) {
        
        object *inv, room;
        int i, room_full;
        inv = all_inventory(this_object());
        for (i=0;i<sizeof(inv);i++){
                if (!inv[i]->query("dungeon_npc")) room_full++;
        }
        if (room_full>1) {
                call_out("jump_down",2,ob);
                ob->start_busy(3);
        }       
}  
int jump_down(object me)        {
        object room;
        if(!objectp(me)) return 1;
        if (me->is_ghost()) return 1;
        message_vision("$N��ҡ���Σ��Ҳ�������֮�أ�һ������ٲ���������ȥ��\n",me);
        tell_object(me,YEL"��Խ׹Խ�죮���������ƺ�������һ���ҽУ�����ë���Ȼ��\n"NOR);
        tell_object(me,YEL"��ͨһ������һͷ������̶ˮ�С�\n\n"NOR);
        room=find_object("/d/eren/waterfall");
        if(!objectp(room)) 
                room = load_object("/d/eren/waterfall"); 
        me->move(room);
        message_vision(HIG"$Nʪ���ܵش�ˮ�︡���������ϰ���\n"NOR,me);
        return 1;
}     
