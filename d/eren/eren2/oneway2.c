 inherit ROOM;
void create()
{
        set("short", "һ����");
        set("long", @LONG
�����ϣ���·������Ţ�������ֽŲ��ã������ϵεδ���������ˮ��
����������С�꣬����������¡¡֮����������������ǧ�������ڸߴ���
�ڡ�����Խ��Խǿ����ǿ�ز���ˮ��
LONG
        );
        set("exits", ([ 
                "westdown" : __DIR__"oneway1",
                "southup" : __DIR__"oneway3",
                        ]));
        set("outdoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object obj, string dir){
        int i;
        object *inv;
        if(dir == "southup" && !obj->query("wizard")){
                inv = all_inventory(this_object());
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i]) ||!inv[i]->is_character()
                                ||inv[i]->is_corpse()) 
                                        continue;
                        if (inv[i]->query("dungeon_npc")=="eren2")
                                return notify_fail(inv[i]->name()+"���ֵ�ס�����·��\n");
                }
        }       
        return 1;
}
