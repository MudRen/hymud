#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

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
	      set_name("[37m����֮��װ[2;37;0m", ({ "huangyu cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[37m����֮��װ[2;37;0m����һ�����൱��Ӳ��[1;33m����[2;37;0m����[32m���˿[2;37;0m�Ƴɣ��ذ˽�������Ǯ��[37m����֮��װ[2;37;0m��
�ۺ�����[37m������˫[2;37;0m �������൱��̣�����[35m�������[2;37;0m�ķ�������
������˼����ŷ��ţ�
[36mľ[2;37;0m:[35m��׼[2;37;0m [33m��[2;37;0m:[1;31m��˫[2;37;0m [1;35m��[2;37;0m:[1;32mħ��[2;37;0m 
[1;37m��[2;37;0m:[1;31m��˫[2;37;0m [1;34m��[2;37;0m:[1;34m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m��Ԫ[2;37;0m ��Դ:[36m����[2;37;0m 
����:[34mϸ��[2;37;0m ����:[32m�ֲ�[2;37;0m 
��ʯ:[32m�ֲ�[2;37;0m ����:[33m�ܸ�[2;37;0m 

�Լ�һ�Ź�׭�֡� [1;32mС��[2;37;0m ������һЩ�� [1;32m�ڹ�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "horse");
		set("ownername", "С��");
		set("value", 16000);
		set("armor_prop/intelligence",40);
		set("armor_prop/strength",40);
		set("armor_prop/karey",18);
		set("armor_prop/percao",32);
		set("armor_prop/dexerity",56);
		set("armor_prop/constitution",25);
    set("armor_prop/dodge", 30);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 44);


    set("armor_prop/armor", 1077);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 40);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 460);

    set("wtypeA",0);
    set("wtypeB",5);
    set("wtypeC",4);
    set("wtypeD",4);
    set("wtypeE",12);
    set("wtypeF",9);
    set("wtypeG",12);
    set("wtypeH",8);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",3);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";