 inherit ROOM;
void create()
{
        set("short", "���ׯ");
        set("long", @LONG
�����������ׯԺ����ڵĴ��Ž��գ����������ɸ�ǽ��ǽ�ϵ����ŷ浶��
����û���ˣ��������������κε����죬����ׯԺ������һ��Ī����������ɭ֮�С�
ׯԺռ�ؼ��㣬��ȫ��������Χ��û�н������ݣ�����û��һ�ã�ȴ���һ��Ϫ����
Ϫ��֮�����Ǹ�ǽ������ڶ�װ����դ��
LONG
        );
        set("exits", ([ 
                "northwest": __DIR__"eroad2",
        ]));
        set("outdoors", "taiping");
        set("item_desc", ([  
                "door": "���Źص������ģ�����û��һ˿������\n",
                "����": "���Źص������ģ�����û��һ˿������\n",
        ]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}   
void init() {
        add_action("do_knock","knock");
        add_action("do_push","push");
}  
int do_knock(string arg) {
        
        if (arg=="door" || arg =="����" || arg =="��"){
                message_vision("$N��������˼��£�������һ˿����Ҳû�С�\n",this_player());
                return 1;
        }
        return 0;
}  
int do_push(string arg) {
        
        if (arg=="door" || arg =="����" || arg =="��") {
                message_vision("$N�����������ţ�������˿������\n",this_player());
           return 1;
        }
        return 0;
}    
