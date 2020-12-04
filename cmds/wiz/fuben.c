       // This program is a part of NITAN MudLIB 
       // Written by Lonely@IsMUD.net (16/05/2009)  
       // fuben.c ��������ָ�� 
        
#include <ansi.h> 
        
inherit F_CLEAN_UP; 
        
int help (object me);
string appromix_time(int n, int flag) 
{ 
             string s; 
             string os; 
             int odd; 
             int bn; 
      
             if (n <= 0) 
                     return flag ? "���Ͼ�" : "����"; 
      
             bn = 1; 
             if (n < bn * 60) 
             { 
                     // bn ��λ������ 
                     s = "����"; 
                     odd = 0; 
             } else 
             if (bn *= 60, n < bn * 60) 
             { 
                     // bn ��λ�Ƿ��� 
                     s = "����"; 
                     os = "����"; 
                     odd = n % bn; 
                     n /= bn; 
             } else 
             if (bn *= 60, n < 24 * bn) 
             { 
                     // bn ��λ��Сʱ 
                     s = "Сʱ"; 
                     os = "����"; 
                     odd = (n % bn) / 60; 
                     n /= bn; 
             } else 
             if (bn *= 24, n < 30 * bn) 
             { 
                    // bn ��λ���� 
                     s = "��"; 
                     os = "Сʱ"; 
                     odd = (n % bn) / (60 * 60); 
                     n /= bn; 
             } else 
             if (n < 365 * bn) 
             { 
                     // bn ��λ���� 
                     s = "����"; 
                     os = "��"; 
                     odd = (n % (30 * bn)) / bn; 
                     n /= 30 * bn; 
             } else 
             { 
                     // bn ��λ���� 
                     s = "��"; 
                     os = "����"; 
                     odd = (n % (365 * bn)) / (bn * 30); 
                     n /= 365 * bn; 
             } 
      
             s = chinese_number(n) + s; 
             if (odd) 
                     s += "��" + chinese_number(odd) + os; 
      
             if (flag) s += "�Ժ�"; 
             return s; 
}  
int main(object me,string arg) 
{ 
              int i, j; 
              string cmd; 
              string fbname; 
              string owner; 
              mixed  ks,os; 
              mapping all, data, temp; 
              string msg = ""; 
               
//              if( !SECURITY_D->valid_grant(me, "(wizard)") ) 
//                      return 0; 
       
              if( !arg ) {  
                      help( me );  
                      return 1; 
              } 
      
              if( sscanf(arg,"%s %s %s",cmd, fbname, owner) != 3 && 
                  sscanf(arg,"%s %s",cmd, fbname) != 2 ) 
                      cmd = arg; 
               
              all  = FUBEN_D->query_fuben_all(); 
              data = FUBEN_D->query_fuben_data();          
              if( !stringp(fbname) ) { 
                      if( !all ) return notify_fail("��̶����û���κθ�����\n"); 
                     msg += "��̶���ڿ����ĸ����ռ����£�\n"; 
                      msg += "������������������������������������\n"; 
                      ks = keys(all); 
                      for( i=0;i<sizeof(ks);i++ ) {  
                              temp=all[ks[i]]; 
                             if( mapp(temp) && sizeof(temp) ) { 
                                      os = keys(temp); 
                                      for( j=0;j<sizeof(os);j++ )  
                                              msg += sprintf("�������ƣ�%-33sʣ��ʱ�䣺%s\n",  
                                                      data[ks[i]]["name"]+"<"+ks[i]+">("+os[j]+")",  
                                                      appromix_time(temp[os[j]] - time(),0));  
                              } 
                                       
                      } 
                      me->start_more(msg); 
                      return 1; 
              } else { 
                      if( cmd == "open" ) { 
                              FUBEN_D->open_fuben(me, fbname); 
                              return 1; 
                      } else if( cmd == "close" ) { 
                              FUBEN_D->close_fuben(me, fbname); 
                              return 1; 
                      } 
       
                     if( fbname != "all" && (undefinedp(data[fbname]) || 
                          undefinedp(all[fbname])) ) 
                              return notify_fail("��̶����û�����������\n"); 
                               
                      if( cmd == "list" ) { 
                              msg += sprintf("��̶���ڿ�����%s�����ռ����£�\n", (fbname=="all")?"����":data[fbname]["name"]); 
                              msg += "������������������������������������\n";                                                
                              if( fbname == "all" ) { 
                                      ks = keys(data); 
                                      for( i=0;i<sizeof(ks);i++ ) { 
                                              msg += sprintf("�������ƣ�%-23s���Ҫ��%-8s����ʱ�䣺%s\n",  
                                                     data[ks[i]]["name"]+"<"+ks[i]+">",  
                                                     (!undefinedp(data[ks[i]]["team"]))?"����":"����", 
                                                     appromix_time(to_int(data[ks[i]]["time"]),0));  
                                      } 
                              } else { 
                                      temp = all[fbname]; 
                                      ks = keys(temp); 
                                      for( i=0;i<sizeof(ks);i++ ) { 
                                              msg += sprintf("�������ƣ�%-33sʣ��ʱ�䣺%s\n",  
                                                     data[fbname]["name"]+"<"+fbname+">("+ks[i]+")",  
                                                     appromix_time(temp[ks[i]] - time(),0));  
                                      } 
                              } 
                              me->start_more(msg); 
                              return 1; 
                      } else if( cmd == "dest" ) { 
                              if( !stringp(owner) ) { 
                                      ks = keys(all[fbname]); 
                                      for( i=0;i<sizeof(ks);i++ )  
                                              FUBEN_D->clear_fuben(fbname, ks[i]); 
                                      write("OK.\n"); 
                                      return 1; 
       
                              } else { 
                                      FUBEN_D->clear_fuben(fbname, owner); 
                                     write("OK.\n"); 
                                     return 1; 
                             } 
      
                     } else { 
                             help(me); 
                             return 1; 
                     } 
             } 
             return 1; 
     } 
      
int help (object me) 
{ 
                           write(@HELP 
     ָ���ʽ : fuben list [��������] 
                fuben dest  ��������  [��������] 
      
     fuben list                    �鿴��ǰ��Ϸ�����еĸ�����ϸ��Ϣ 
     fuben list ��������           �鿴ָ����������ϸ��Ϣ 
     fuben open|dest all|��������  �鿴ָ����������ϸ��Ϣ 
     fuben dest ��������           ����ָ�����͸��������и��� 
     fuben dest �������� ��������  ����ָ�����͸�����ĳ�˸��� 
HELP
        );
                           return 1; 
}