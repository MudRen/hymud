#include <ansi.h>
inherit ITEM; 

void create() 
{ 
                
           set_name(RED"����������"NOR, ({ "fuben door", "door" }) ); 
            set_weight(5); 
               if( clonep() ) 
                       set_default_object(__FILE__); 
              else { 
                     set("long", HIB"Ŀǰ�Ĺ����У�\n"+ 
                                  "enter <�Թ�����>������һ�������Լ��������Թ�������\n"+ 
                                  "�Թ����룺forest-ԭʼɭ�֣�desert-�޾���Į��dragon-������ӡ��necropolis-����Ĺ԰��temple-ʧ������mausoleum-�ػ���Ĺ��\n"+ 
                                  "\n"NOR);  
                      set("unit", "��"); 
                      set("no_get",1); 
                      set("value", 20); 
              } 
              setup(); 
      } 
       
      void init() 
      { 
              add_action("do_enter","enter"); 
      } 
       
      int do_enter(string arg)  
     { 
              int valid; 
                       
             if( !arg || arg == "" ) 
                      return 0; 
               
              valid = FUBEN_D->valid_enter(this_player(), arg);  
              if( valid >=1 ) 
                      FUBEN_D->enter_fuben(this_player(), arg); 
              else { 
                      if( valid == 0 ) 
                              write("��ʵս���鲻�㣬���������в��⣬����������һ�������ɡ�\n"); 
                      else if( valid == -1 ) 
                              write("������̫���ˣ��Ͳ�Ҫ��ȥ�۸���Щ������С�����˰ɡ�\n"); 
                      else if( valid == -2 ) 
                              write("��Ϸ��Ŀǰ��û�п��Ÿø����������˶Ժ����ԡ�\n"); 
                      else if( valid == -3 ) 
                              write("�ø�������IP���ؽ��룬���Ѿ�����������ޡ�\n"); 
                      else if( valid == -4 ) 
                              write("�ø�������ʦ�رգ�����ʱ�޷����롣\n"); 
                      else if( valid == -5 ) 
                              write("�����ϴν��븱��ʱ��̫�̣�����Ϣ��������\n"); 
                      else if( valid == -6 ) 
                              write("�ø���������Ӳ��ܽ��롣\n"); 
                      else if( valid == -7 ) 
                              write("��Ķ������������ø����涨�����ޡ�\n"); 
              }         
              return 1; 
      } 