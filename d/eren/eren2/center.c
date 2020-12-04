 inherit ROOM;
#include <ansi.h>
string *roomname= ({"gold", "silver", "copper", "iron","tin", "center", }); 
void create()
{
        set("short", "�˽��͵�����");
        set("long", @LONG
���ﾹ�Ǹ��˽��͵����ӣ��ǰ���ǽ���е��������е��Ǹ֣��е���
ʯ�壬������һ�����ǽ��ӡ������û�����ӣ�û�г��ӣ���Ϊ�ڵصף�
����Ҳû������������������Ҳ��֪����������ġ�������ֻ�н��̣���
��СС����״��ͬ�Ļ��ؽ��̣��е����������е���ʯ�죬��Ȼ��Ҳ�е�
�ǽ��ӵġ����������и��߸ߵ�ͭ����
LONG
        );
        set("no_magic",1);
        set("exits", ([ 
                        ]));
        set("item_desc", ([
                "�����": "һ�������ƳɵĻ��ؽ���(goldwheel)���ƺ�����ת����turn����\n",
                "������": "һ�������ƳɵĻ��ؽ���(silverwheel)���ƺ�����ת����turn����\n",
                "������": "һ�������ƳɵĻ��ؽ���(ironwheel)���ƺ�����ת����turn����\n",
                "ͭ����": "һ����ͭ�ƳɵĻ��ؽ���(copperwheel)���ƺ�����ת����turn����\n",
                "������": "һ�������ƳɵĻ��ؽ���(tinwheel)���ƺ�����ת����turn����\n",
                "ͭ��": "ͭ��(ring)���úܸߣ���������pull���ܷ�����\n",
                "ʯ����": "һ��ʯ�ʵĽ��̣����������Ѿ���ס�ˡ�\n",
                "ľ����": "һ��ľ�ʵĽ��̣����������Ѿ�����ˡ�\n",
                "����": "һ�������СС����״��ͬ�Ļ��ؽ��̣�������(ironwheel)��
����(silverwheel)��ͭ��(copperwheel)������(tinwheel)��
���(goldwheel)���������ܵ�(earthwheel)��ʯ�̵�(stonewheel)��
��ľ���(woodwheel)��\n",
                "goldwheel": "һ�������ƳɵĻ��ؽ���(goldwheel)���ƺ�����ת����turn����\n",
                "silverwheel": "һ�������ƳɵĻ��ؽ���(silverwheel)���ƺ�����ת����turn����\n",
                "ironwheel": "һ�������ƳɵĻ��ؽ���(ironwheel)���ƺ�����ת����turn����\n",
                "copperwheel": "һ����ͭ�ƳɵĻ��ؽ���(copperwheel)���ƺ�����ת����turn����\n",
                "tinwheel": "һ�������ƳɵĻ��ؽ���(tinwheel)���ƺ�����ת����turn����\n",
                "ring": "ͭ�����úܸߣ���������pull���ܷ�����\n",
                "stonewheel": "һ��ʯ�ʵĽ��̣����������Ѿ���ס�ˡ�\n",
                "woodwheel": "һ��ľ�ʵĽ��̣����������Ѿ�����ˡ�\n",
                "wheel": "һ�������СС����״��ͬ�Ļ��ؽ��̣���������(ironwheel)��
����(silverwheel)��ͭ��(copperwheel)������(tinwheel)��
���(goldwheel)������ʯ�̵�(stonewheel)��ľ���(woodwheel)��\n",
                "jiaopan": "һ�������СС����״��ͬ�Ļ��ؽ��̣���������(ironwheel)��
����(silverwheel)��ͭ��(copperwheel)������(tinwheel)��
���(goldwheel)������ʯ�̵�(stonewheel)��ľ���(woodwheel)��\n",
                ]) );
        
        set("objects", ([
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init()
{
        add_action("do_turn", "turn");
        add_action("do_pull", "pull");
} 
int do_pull(string arg) 
{
        if (arg != "ring" && arg !="ͭ��") {
                write("��Ҫ��ʲô��\n");
                return 1;
                }
        message_vision(YEL"$Nƴ��һʹ����ͭ��ͻȻ��ȫ����������\n"NOR,this_player());
        call_out("flood_them",6);
        this_player()->start_busy(3);
        return 1;
} 
int do_turn(string arg)
{
        object obj;
        object me, room;
        string room_name;
        
        if (arg == "woodwheel" || arg =="stonewheel"
                || arg == "ʯ����" || arg == "ľ����") {
                write("������̺����ˣ�ת������\n");
                return 1;
        }
        
        if (arg == "����")
                return notify_fail("��Ҫת�ĸ����̣�\n"); 
        
        if(!arg || (arg!="goldwheel" && arg != "tinwheel" 
                && arg!="copperwheel" && arg!="ironwheel" && arg!="silverwheel"
                && arg!="�����" && arg != "������" 
                && arg!="ͭ����" && arg!="������" && arg!="������"))            
                        return notify_fail("��Ҫתʲô��\n");
                
        switch (arg) {
                        case "�����": arg="goldwheel";break; 
                        case "������": arg="tinwheel";break;
                        case "ͭ����": arg="copperwheel";break;
                        case "������": arg="ironwheel";break;
                        case "������": arg="silverwheel";break;
                        default: break;
                }
                if (sscanf(arg, "%swheel", room_name)!= 1) 
                        return notify_fail("��Ҫתʲô��\n");                   
                room=find_object(__DIR__+room_name);
                if(!objectp(room)) 
                        room = load_object(__DIR__+room_name);
                if (query("exits/"+room_name)) 
                        return notify_fail("����̿��Ƶ����Ѿ��ǿ��ŵ��ˡ�\n");
                message_vision("����$Nת�����̣�ʯ�ڿ�ʼ��ת������¶����һ���š�\n",this_player());
                delete("exits");
                set("exits/"+room_name,__DIR__+room_name);
                return 1;
        
} 
int flood_them() {
        object room, *inv,ob,exit_room;
        int i,j;
        exit_room=find_object(__DIR__"river1");
        if(!objectp(exit_room)) 
                exit_room = load_object(__DIR__"river1"); 
        for (i=0;i<sizeof(roomname);i++){
                room=find_object(__DIR__+roomname[i]);
           if(!objectp(room)) 
                        room = load_object(__DIR__+roomname[i]); 
        message("vision",HIG"ֻ������¡¡��һ�������𣬾ͺ���ɽ�������Ƶģ�����һ����ǽ��
ͻȻ����ȫ������һ�ɺ�ˮ��������ɽ����һ�㵹���˽�����\n\n"NOR,room);
                inv = all_inventory(room);
                for(j=0;j<sizeof(inv);j++){
                        ob = inv[j];
                        if (!userp(ob))continue;
                        message_vision(HIG"һ�����У�$N���ɼ��ر�ˮ��������ȥ��\n\n"NOR,ob);
                        message("vision",HIG"ˮ����Ʈ��һ��������\n"NOR,exit_room);
                        ob->start_busy(2);
                        ob->move(exit_room);
                }
        }
        return 1;
}  
void reset()
{
        ::reset();
        delete("exits");
        
}       
