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
	      set_name("[1;31mÁ¶ÓüÖ®Åû·ç[2;37;0m", ({ "lianyu armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[1;31mÈıÊ®ÈıÌìÏÂÓĞµØ£¬µØÏÂÓĞ³Ç£¬³ÇÃû¹í³Ç£¬´óĞ¡ÑıÄ§£¬ÈËÉñĞóÉú¶¼ÔÚ´ËÂÖ»ØÍù·µ£¬Î½Ö®¡°Á¶Óü¡±£¡
[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ[31mÍòÄêÉñÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØ¶ş½ïÁùÁ½ËÄÇ®µÄ[1;31mÁ¶ÓüÖ®Åû·ç[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;31mÎŞË«[2;37;0m [36mÄ¾[2;37;0m:[1;36mÍêÃÀ[2;37;0m [32mË®[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;35m¾øÊÀ[2;37;0m 
[1;37mÀ×[2;37;0m:[35m±ê×¼[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m»ÙÌì[2;37;0m ÌìĞş:[34mÏ¸Ëé[2;37;0m ÇÉÖÆ:[31m¾«ÖÂ[2;37;0m 
°×Ê¯:[35m±ê×¼[2;37;0m ÖÜÌì:[34mÏ¸Ëé[2;37;0m ³¤Éú:[31m¾«ÖÂ[2;37;0m ²»ÀÏ:[33mºÜ¸ß[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÍò½£´©ĞÄ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÊÖ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "box");
		set("ownername", "Íò½£´©ĞÄ");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",40);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",32);
		set("armor_prop/constitution",40);
    set("armor_prop/dodge", 54);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 227);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 25);
    set("armor_prop/qi", 62);
    set("armor_prop/jing", 44);
    set("armor_prop/jingli", 44);
    set("armor_prop/damage", 133);

    set("wtypeA",12);
    set("wtypeB",7);
    set("wtypeC",8);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",11);
    set("wtypeG",5);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "hand",
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