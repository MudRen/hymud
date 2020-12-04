#include <ansi.h> 
#include <armor.h>

inherit HANDS;

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
	      set_name("[1;32mÎŞ¼«Ö®ÊÖÌ×[2;37;0m", ({ "wuji hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¸±");
		set("long", @LONG
[1;32m´ËÎïÒÑ´ï³öÉñÈë»¯£¬µÇ·åÔì¼«£¬ÉñºõÆäÉñÖ®¾³½ç£¡Ë×ËµÍòÎï¹é×Ú£¬±ãÊÇÕâ¡°ÎŞ¼«¡±£¡
[2;37;0mÕâÊÇÒ»¸±ÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[37mÌì²ÏË¿[2;37;0mÖÆ³É£¬ÖØÎå½ïÁùÁ½¾ÅÇ®µÄ[1;32mÎŞ¼«Ö®ÊÖÌ×[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[35m±ê×¼[2;37;0m [32mË®[2;37;0m:[1;32mÄ§Íõ[2;37;0m [31m»ğ[2;37;0m:[1;31m¿ªÔª[2;37;0m [1;35m·ç[2;37;0m:[1;32mÄ§Íõ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m»ÙÌì[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
×ÏÊ¯:[33mºÜ¸ß[2;37;0m ÉÁµç:[33mºÜ¸ß[2;37;0m 
ÖÜÌì:[35m±ê×¼[2;37;0m ³¤Éú:[35m±ê×¼[2;37;0m ÍşÁ¦:[32m´Ö²Ú[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m·ç·ç[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m¸«·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lingdy");
		set("ownername", "·ç·ç");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",56);
		set("armor_prop/karey",48);
		set("armor_prop/percao",56);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",56);
    set("armor_prop/dodge", 56);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 56);


    set("armor_prop/armor", 648);
    set("armor_prop/defense", 56);
    
    set("armor_prop/neili", 52);
    set("armor_prop/qi", 57);
    set("armor_prop/jing", 56);
    set("armor_prop/jingli", 56);
    set("armor_prop/damage", 1336);

    set("wtypeA",5);
    set("wtypeB",5);
    set("wtypeC",9);
    set("wtypeD",13);
    set("wtypeE",6);
    set("wtypeF",9);
    set("wtypeG",7);
    set("wtypeH",6);
    set("wtypeI",5);
    set("wtypeJ",6);
    set("wtypeK",7);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";