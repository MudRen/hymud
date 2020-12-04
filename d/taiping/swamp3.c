 inherit ROOM;
void create()
{
        set("short", "����ر�Ե");
        set("long", @LONG
����������صı�Ե��«έ�ܸߣ����ų�����Ҷ�ӣ��������ɫ��ë��������
����Ƥ�װ׵ģ���ϸϡ���Ҷ�ӹ������ϡ�ˮ�ܻ��ǣ��������ף���������������
������Ϊ�������˵��ˮԽ�룬��������Խ�࣬ÿ�����������ʱ�����˼���
���߳��Ĵ����Ծ��ˮ�档
LONG
        );
        set("exits", ([ 
                "east": __DIR__"swamp2",
        ]));
        set("outdoors", "taiping");
        set("item_desc", ([
                    
        ]));
        set("objects", ([
                __DIR__"npc/oldfishman": 1,
        ]));
        set("resource/water",1);
        set("liquid/container","��ˮ");
        set("coor/x",-1000);
        set("coor/y",150);
        set("coor/z",0);
        setup(); 
}  
void fish_notify(object obj){
        object me, room, fish, *inv, bait;
        int i;
        
        me = this_player();
        inv = all_inventory(obj);
        if(sizeof(inv) == 0){
                message("vision",me->name() + "�ͳ���" + obj->name() + "�ַ��˻�ȥ��\n", environment(me), me);
                tell_object(me, obj->name() + "��û�ж���ô���Ե����� ? \n");           
                return;
        }               
        for(i=0; i<sizeof(inv); i++) {
           if(inv[i]->query("fish_bait")) {
                        bait = inv[i];
                        message_vision("$N�Ӷ���һ��," + obj->name() + "�ڿ��л���һ��Ư���Ļ���, �㹳������ˮ��. \n" , me);
                        me->start_busy(5);
                        remove_call_out("do_fishing");              
                        call_out("do_fishing", 5, me, bait);                    
                        return;
                } 
        }
        tell_object(me, "���õĶ���̫�԰� ? \n");                       
        return;
} 
void do_fishing(object me, object bait){
        object  fish; 
        if(me && environment(me) == this_object()) {
                message_vision("$N�ܿ��ֳ�����һ�����, " , me);
                switch (random(3)) {
                        case 0:         message_vision("ȴʲô��û������ ! \n", me);
                                        break;
                        case 1:         message_vision("ʲô��û������ , ���ȴ������� !!  \n", me);
                                        destruct(bait);                         
                                        break;
                        case 2:
                                        if (bait->query("fish_bait_real")){        
                                                message_vision("�㹳�ϵ�����һ�������㣡������  \n", me);
                                                fish = new(__DIR__"obj/dragonfish");
                                                fish->move(me);
                                        } else {      
                                                message_vision("�㹳�ϵ���һ������ ����  \n", me);
                                                fish = new(__DIR__"obj/fish");
                                                fish->move(me);
                                        }
                                        destruct(bait);
                                        break;
                }
        }
        return;
}  
