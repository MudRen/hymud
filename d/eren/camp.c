 inherit ROOM;
void create()
{
        set("short", "Ӫ��");
        set("long", @LONG
����Լ��ʮ�ɼ������������Ӷ��𼸸����Ρ��������뺷����������һ��Ⱦƣ�
б���۴������㡣��һ�������һ��ͷ�����������µ�ë�����ӣ�һ��ִ�ž�
����һ�ְ�����������ʯ���ĺ�������������۹�ɨ������ŭ������
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"banditcamp1",
                "north" : __DIR__"innercamp",
                        ]));
        set("objects", ([
                __DIR__"npc/banditleader" : 1,
        ])); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object obj, string dir){
        int i;
        object *inv;
        if(dir == "north"){
                inv = all_inventory(this_object());
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i]) ||!inv[i]->is_character()
                                ||inv[i]->is_corpse()) 
                                        continue;
                        if (inv[i]->query("dungeon_npc")=="eren")
                                return notify_fail(inv[i]->name()+"��ס�����·��\n");
                }
        }       
        return 1;
}      
