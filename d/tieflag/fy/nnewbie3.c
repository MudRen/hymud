 inherit ROOM;
void create()
{
                object silver;
        set("short", "�����");
        set("long", @long
��������һƬ����Ǭˬ��������Ȼ�������˰��˺ܶණ����������Ȼ��
�úܿ������ϻ���һЩʪ�����Ľ�ӡ����Ȼ��������������żȻ�������һ
����Ӱ��Ҳ�����û̿֡������ƺ��Ե��ϵı��ﲢ��̰����ֻȡȥ�Լ����裬
�������뿪��
long
        );
        set("exits", ([ /* sizeof() == 4 */
"out" : __DIR__"nnewbie2",
  "enter" : __DIR__"nnewbie4",
  
]));
        set("objects", ([
                /*__DIR__"obj/gui1" : 1,
                "/d/loulan/npc/obj/sword2" :1,
"/d/cave/npc/obj/windsword" : 1,
"/d/wolfmount/npc/obj/zheshan" : 1,
"/d/qianjin/npc/obj/toysword" :1,
"/d/shaolin/npc/obj/xiesword" : 1,*/

/*"/d/palace/g/npc/obj/s_spear" :1,
"/d/palace/g/npc/obj/g_spear":1,
"/obj/weapon/sword_katana":1,
"/d/wolfmount/npc/obj/rockhammer":1,
"/d/wolfmount/npc/obj/juque":1,
"/d/palace/npc/obj/wolf_hammer":1,*/
"/d/tieflag/fy/npc/obj/guzi": 1,
/*"/d/taishan/npc/obj/bamboo_staff":
"/d/songshan/npc/obj/dafeng":*/
                
                        ]) );
        set("indoors", "fengyun");
                set("no_fight",1);

        set("coor/x",0);
        set("coor/y",30);
        set("coor/z",-10);
        
        setup();
    silver = present("guzi",this_object());
    silver->set_amount(random(9876)+1234);    

}
