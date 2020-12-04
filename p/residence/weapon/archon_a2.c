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
	      set_name("[1;36mÌìµØÖ®·ş×°[2;37;0m", ({ "tiandi cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[1;36mÌìµØÖ®³õ£¬Å®æ´²¹ÌìËùÁôÏÂµÄÌìµØ¼äÖÁ×ğÖ®ÎïÖ®Ò»¾­Ç§ÇïÍòÔØËùÖÆ£¬¹¦ÄÜ¿ªÌìÅüµØ£¡
[2;37;0mÕâÊÇÒ»¼şÓÉ¾ø¶Ô¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØËÄ½ï°ËÁ½ËÄÇ®µÄ[1;36mÌìµØÖ®·ş×°[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´¾ø¶Ô¼á¹Ì£¬¾ßÓĞ[31mÎŞÓëÂ×±È[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;35m¾øÊÀ[2;37;0m [36mÄ¾[2;37;0m:[1;35m¾øÊÀ[2;37;0m [31m»ğ[2;37;0m:[1;35m¾øÊÀ[2;37;0m [33mÍÁ[2;37;0m:[1;31m´´ÊÀ[2;37;0m [1;37mÀ×[2;37;0m:[1;31m´´ÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m»ÙÌì[2;37;0m ÌìÓî:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[32m´Ö²Ú[2;37;0m 
°×Ê¯:[31m¾«ÖÂ[2;37;0m ×ÏÊ¯:[33mºÜ¸ß[2;37;0m ÉÁµç:[35m±ê×¼[2;37;0m 
ÖÜÌì:[35m±ê×¼[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÌìÕı[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m½£·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "archon");
		set("ownername", "ÌìÕı");
		set("value", 25000);
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",48);
		set("armor_prop/karey",48);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",56);
		set("armor_prop/constitution",56);
    set("armor_prop/dodge", 60);
    set("armor_prop/parry", 49);
    set("armor_prop/attack", 58);


    set("armor_prop/armor", 1062);
    set("armor_prop/defense", 40);
    
    set("armor_prop/neili", 59);
    set("armor_prop/qi", 56);
    set("armor_prop/jing", 48);
    set("armor_prop/jingli", 40);
    set("armor_prop/damage", 376);

    set("wtypeA",11);
    set("wtypeB",11);
    set("wtypeC",5);
    set("wtypeD",11);
    set("wtypeE",14);
    set("wtypeF",5);
    set("wtypeG",14);
    set("wtypeH",6);
    set("wtypeI",8);
    set("wtypeJ",10);
    set("wtypeK",10);
    set("wtypeL",7);
    
    
                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 18);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";