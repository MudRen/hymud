 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ˮ����");
        set("long", @LONG
����û�������е���ô�����Ժ�����Ŀ�����׵�һ�У����׳���
�˸�ɫ��ɺ���ͱ�������������м���һ�������Ķ��壬���Ͼ�Ȼû��˿
�����Σ��㲻�ɵ�ת����������ߡ���Զ����һ��ʯ��������������ƴ����
���֣�ˮ��֮�ţ���
LONG
        );
   set("exits", ([ 
      "enter" : __DIR__"gongnei",
      "up" : __DIR__"lake",
   ]));
        set("coor/x",200);
        set("coor/y",12300);
        set("coor/z",0);
        setup();
} 
void init()
{
   remove_call_out("do_air");
   call_out("do_air",6, this_object()); 
} 
int do_air(object ob) 
{
   object *inv;
   int  i, da; 
   inv = all_inventory(this_object());
   if(sizeof(inv) == 0) return 1;
   for(i=0;i<sizeof(inv);i++) {
      if(userp(inv[i])) {
         tell_object(inv[i], "��ֻ�����ؿڷ��ƣ����ǿ���뿪����ɡ�\n");
         da = 50000 / (inv[i]->query("max_neili")+1);
         if(da>100) da = 50;
         if(da<10) da = 10;
         inv[i]->receive_damage("qi", da); 
      }
   }
   call_out("do_air", 5+random(10), this_object());
}   
