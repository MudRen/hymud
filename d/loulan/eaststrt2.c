 inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
һ���ƻ�ͨ���ĳ��ȣ��ƺ�ԭ�ȱ��Ƿ����Ľֵ���������һЩ��Ժ��լ����
�������ռ�����¥���ĵ��������󣬱㽫���СС����լ���ݸĽ����Թ�����
��ɫ������ʹ��������ʮ�����Լ��ڶ��������˺�һ�����˾�ס��
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"eaststrt",
                "north" : __DIR__"baihuagong",
                "east" : __DIR__"eaststrt3",
        ]));
        set("objects", ([
               __DIR__"npc/guard2" : 1,
        ]) );
        set("indoors", "loulan"); 
        set("coor/x",-980);
        set("coor/y",200);
        set("coor/z",-100);
        setup();
} 
int valid_leave(object me, string dir)
{
        object ob;
        object *inv;
        int i;
        int j;
        int k;
        j=0;
        k=0;
        if ( !userp(me) || dir=="west" || dir=="east")
                return 1;
        
        inv=all_inventory(this_object());
        for (i=0;i<sizeof(inv);i++)     {
                if (inv[i]->query("id")=="sun chiqi") j=1;
        }               
           if (j==0) return 1; 
        inv=all_inventory(me);
        for(i=0; i<sizeof(inv); i++)            {
                if(inv[i]->query("owner")=="������" && (int)inv[i]->query("equipped"))
                        k = 1;
        }
        if (k==0) return notify_fail("�����������ס���ȥ·��\n");
        return 1;
}   
