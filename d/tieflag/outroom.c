 // é����
// QC and modified by Tie
inherit ROOM; 
void create()
{
        set("short", "é����");
        set("long", @LONG
ǰ���Ǵ�ɽ�ȣ������Բԣ���ɽ��ľ������ɽ���ϣ�����ª�Ľ������������
���é�ݣ�é��ǰ��������ľ�ƣ�������һ����������é����Ʈɢ��������
�����ƺ�����̽�׳������������˼��ۡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"maoroom",
  "southdown" : __DIR__"road1",
])); 
        set("item_desc", ([
                "sign": "               
                                        С
                                        С
                                        ��
                                        ��
                                        ��\n"
        ]) );
        set("outdoors", "tieflag");
        set("coor/x",60);
        set("coor/y",2010);
        set("coor/z",30);
        setup();
}
void init()
{
        add_action("do_hit","strike");
} 
int do_hit(string arg)
{
        object ob;
if( (arg == "sign" || arg == "ľ��") && query("already") < 10) 
{
        tell_object(this_player(),"���ľ���ͻ�һ�ƣ���������һС�飡\n");      
   ob=new(__DIR__"obj/woodpiece");
        ob->move(this_object());
        this_object()->add("already",1);
        return 1;
        }
        return 0;
}
void reset()
{
:: reset();
delete("already");
} 
