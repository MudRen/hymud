#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[33m���֮����[2;37;0m", ({ "hongjun armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[33m���֮����[2;37;0m����һ����ʮ�ּ�Ӳ��[1;33m����[2;37;0m����[32m���˿[2;37;0m�Ƴɣ����Ľ�����һǮ��[33m���֮����[2;37;0m��
�ۺ�����[37m������˫[2;37;0m ������ʮ�ּ�̣�����[36m��С[2;37;0m�ķ�������
������˼����ŷ��ţ�
[36mľ[2;37;0m:[35m��׼[2;37;0m [32mˮ[2;37;0m:[35m��׼[2;37;0m [33m��[2;37;0m:[1;35m����[2;37;0m [1;35m��[2;37;0m:[31m����[2;37;0m 
[1;37m��[2;37;0m:[31m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m��˫[2;37;0m ����:[36m����[2;37;0m ��Դ:[36m����[2;37;0m 
����:[34mϸ��[2;37;0m ����:[34mϸ��[2;37;0m 
����:[36m����[2;37;0m ����:[35m��׼[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m���Ӻ�[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "dzh");
		set("ownername", "���Ӻ�");
		set("value", 16000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",40);
		set("armor_prop/karey",17);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",24);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 93);
    set("armor_prop/defense", 19);
    
    set("armor_prop/neili", 51);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",5);
    set("wtypeC",5);
    set("wtypeD",0);
    set("wtypeE",11);
    set("wtypeF",6);
    set("wtypeG",6);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",5);
    
    
                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 12);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";